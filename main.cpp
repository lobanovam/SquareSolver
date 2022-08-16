#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getCoef(float * u, float * v, float * d);
void linear(float b, float c, float * u);
void quadratic(float a, float b, float c, float * u, float * v, int * d);
void printAnswLinear(float answ1);
void printAnswQuad(float answ1, float answ2);

int main()
{
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    float answ1 = 0.0;
    float answ2 = 0.0;
    int check = 1;

    printf("This program solves the equations of this type: ");
    printf("a*x^2 + b*x + c = 0\n");
    printf("Enter quadratic equation coefficients a, b, c: \n");

    getCoef(&a, &b, &c);

    if (a == 0 && b == 0) {
        if (c != 0) {
            printf("%f = 0 has no solutions\n", c);
            return 0;
        } else {
            printf("there are an infinite number of solutions\n");
            return 0;
        }
    }

    if (a == 0) {
        printf("it's a linear equation\n");
        linear(b, c, &answ1);
        printAnswLinear(answ1);

    } else {
        printf("it's a quadratic equation\n");
        quadratic (a, b, c, &answ1, &answ2, &check);
        if(check)
        printAnswQuad(answ1, answ2);

    }

    printf("Hope that you are satisfied\n");
    return 0;
}



void getCoef(float * u, float * v, float * d)    //u = &a, v = &b, d = &c
{
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    char ch = '0';

    while (scanf("%f %f %f", &a, &b, &c) != 3) {
        printf("incorrect enter, try again\n");
        while ((ch = getchar()) != '\n') {
        continue;
        }
    }
    *u = a;
    *v = b;
    *d = c;
}



void linear(float b, float c, float * u)    //u = &answ1
{
    printf("linear equation has one solution\n");
    *u = -c/b;

}



void quadratic(float a, float b, float c, float * u, float * v, int * d)  //u = &answ1, v = &answ2 d = &check
{
    float disc = 0;
    if ((disc = b*b - 4*a*c) < 0) {
            printf("there are no real solutions\n");
            *d = 0;

        } else if (disc == 0) {
            printf("there is only one solution!\n");
            *u = *v = (-b/(2*a));

        } else {
            printf("there are two solutions!\n");
            *u = ((-b + sqrt(disc))/(2*a));
            *v = ((-b - sqrt(disc))/(2*a));
        }
}

void printAnswLinear(float answ1)
{
    printf("this solution is %f\n", answ1);

}

void printAnswQuad(float answ1, float answ2)
{
    if (answ1 == answ2) {
        printf("this solution is %f\n", answ1);
    } else {
        printf("first solution is %f, second one is %f.\n", answ1, answ2);
    }


}






