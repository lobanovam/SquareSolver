#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void getCoef(float * u, float * v, float * d);
void linear(float b, float c, float * u);
void quadratic(float a, float b, float c, float * u, float * v, int * d);
void printAnsw(float answ1, float answ2, int option);
void solver(float a, float b, float c, float*ans1, float*ans2, int*u);
bool isEqual(float num1, float num2);

void quadratic(float a, float b, float c, float * u, float * v, int * d)  //u = &answ1, v = &answ2 d = &check
{
    float disc = 0;
    if ((disc = b*b - 4*a*c) < 0) {
            printf("since discriminant < 0, ");
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

void printAnsw(float answ1, float answ2, int option)
{
    if (option == 0)
    printf("there are no real solutions\n");
    if (option == 1)
    printf("there are an infinite number of solutions\n");
    if (option == 2)
    printf("this great solution is %f\n", answ1);
    if (option == 3) {
        if (answ1 == answ2) {
            printf("this solution is %f\n", answ1);
        } else {
        printf("first solution is %f, second is %f\n", answ1, answ2);
        }
    }


}

void solver(float a, float b, float c, float*ans1, float*ans2, int *u ) //u = &option, ans1 = &answ1, ans2 = &answ2
{

    *u = 0;
    int check = 1;

    if (isEqual(a, 0) && isEqual(b, 0) ) {
        if (isEqual(c, 0))
        *u = 1;
    }
    else if (isEqual(a, 0)) {
        printf("it's a linear equation\n");
        linear(b, c, ans1);

        *u = 2;

    } else {
        printf("it's a quadratic equation\n");
        quadratic (a, b, c, ans1, ans2, &check);
        if(check)
        *u = 3;
    }


}

void getCoef(float * u, float * v, float * d)    //u = &a, v = &b, d = &c
{
    char ch = '0';

    while (scanf("%f %f %f", u, v, d) != 3) {
        printf("incorrect enter, try again\n");
        while ((ch = getchar()) != '\n') {
        continue;
        }
    }
}


bool isEqual(float num1, float num2)
{
 return(fabs(num1 - num2) < 1E-7);

}
void linear(float b, float c, float * u)    //u = &ans1
{
 printf("linear equation has one solution\n");
    *u = -c/b;

}
