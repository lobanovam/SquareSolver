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
void tester(float answ1, float answ2, float res1, float res2, int i);
void tests();

void quadratic(float a, float b, float c, float * u, float * v, int * d)  //u = &answ1, v = &answ2 d = &check
{
    float disc = 0;
    if ((disc = b*b - 4*a*c) < 0) {
            printf("since discriminant < 0, ");
            *d = 0;
            *u = *v = 0;

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
    printf("Enter quadratic equation coefficients a, b, c: \n");
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

void tester(float answ1, float answ2, float res1, float res2, int i)
{
    if ((isEqual(res1, answ1) && isEqual(res2, answ2))||(isEqual(res2, answ1) && isEqual(res1, answ2))) {
            printf("test #%d is passed\n", i+1);
        }else {
            printf("test #%d is failed\n", i+1);
            printf("expected solutions are %f, %f\n", res1, res2);
        }
}


void tests() {
    float a = 0.0, b = 0.0, c = 0.0, answ1 = 0.0, answ2 = 0.0, res1 = 0.0, res2 = 0.0;
    int option = 0, resct = 0, testCount = 0;

    FILE *pIn = NULL;
    if ((pIn = fopen("tests.txt", "r")) == NULL) {
        printf("can't open file\n");
        return;

    } else {
        printf("file is opened\n");
    }

    fscanf(pIn, "%d", &testCount);
    printf("there is %d tests in total\n", testCount);

    for (int i = 0; i < testCount; i++) {
        fscanf(pIn,"%f %f %f %d", &a, &b, &c, &resct);

        if (resct == 0) {
            res1 = res2 = 0;

        } else if (resct == 1) {
            fscanf(pIn, "%f", &res1);
            res2 = res1;
        }else {
            fscanf(pIn, "%f %f", &res1, &res2);

        }

        solver(a, b, c, &answ1, &answ2, &option);
        printAnsw(answ1, answ2, option);
        tester(answ1, answ2, res1, res2, i);

        printf("***********************\n");

    }
    fclose(pIn);
    return;
}

