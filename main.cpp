#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#define INF_ROOTS 3

void getCoef(float *a, float *b, float *c);
void linear(float b, float c, float *answ1_pt, int *rootcnt_pt);
void quadratic(float a, float b, float c, float *answ1_pt, float *answ2_pt, int *rootcnt_pt);
void printAnsw(float answ1, float answ2, int rootct);
void solver(float a, float b, float c, float *ans1, float *ans2, int *rootcnt_pt);
bool isEqual(float num1, float num2);
void tester(float answ1, float answ2, float res1, float res2, int i);
void tests();
void clearBuff();
const double EPSILON = 1E-7;


int main()
{

    float a = NAN, b = NAN, c = NAN, answ1 = NAN, answ2 = NAN;
    int rootcnt = 0, resct = 0, choice = 0;

    printf("This program solves the equations of this type: ");
    printf("a*x^2 + b*x + c = 0\n");

    printf("press 1 to input coefficients yourself, press 2 to run tests\n");
    while((scanf("%d", &choice) !=1) || (choice != 1 && choice != 2)) {
        printf("please press 1 or 2\n");
        clearBuff();
    }
    clearBuff();
    if(choice == 1) {
        getCoef(&a, &b, &c);
        solver(a, b, c, &answ1, &answ2, &rootcnt);
        printAnsw(answ1, answ2, rootcnt);
    }else {
        tests();
    }
    printf("Hope that you are satisfied\n");
    return 0;
}

void quadratic(float a, float b, float c, float *answ1_pt , float *answ2_pt, int *rootcnt_pt)
{
    assert(answ1_pt != NULL);
    assert(answ2_pt != NULL);
    assert(rootcnt_pt != NULL);
    assert(answ1_pt != answ2_pt);

    float disc = 0;
    if ((disc = b*b - 4*a*c) < 0) {
            fprintf(stderr, "disc < 0\n");//������?//asserts
            *rootcnt_pt = 0;
            *answ1_pt = *answ2_pt = 0;

        } else if (disc == 0) {
            fprintf(stderr, "disc = 0\n");
            *answ1_pt = *answ2_pt = (-b/(2*a));
            *rootcnt_pt = 1;

        } else {
            float sqrt_disc = sqrt(disc);
            fprintf(stderr, "disc > 0\n");
            *answ1_pt = ((-b + sqrt_disc)/(2*a));
            *answ2_pt = ((-b - sqrt_disc)/(2*a));
            *rootcnt_pt = 2;
        }
}

void printAnsw(float answ1, float answ2, int rootcnt)
{

    if (rootcnt == 0)
    printf("there are no real solutions\n");
    if (rootcnt == INF_ROOTS)
    printf("there are an infinite number of solutions\n");
    if (rootcnt == 1)
    printf("there is only one solution, it is %f\n", answ1);
    if (rootcnt == 2) {
        if (isEqual(answ1, answ2)) {
            printf("one solution: %f\n", answ1);
        } else {
        printf("first solution is %f, second is %f\n", answ1, answ2);
        }
    }


}

void solver(float a, float b, float c, float *answ1_pt, float *answ2_pt, int *rootcnt_pt )
{
    int check = 1;
    if (isEqual(a, 0)) {
        linear(b, c, answ1_pt, rootcnt_pt);
        *answ2_pt = *answ1_pt;
    } else {
        quadratic(a, b, c, answ1_pt, answ2_pt, rootcnt_pt);
    }
}

void getCoef(float *a, float *b, float *c)
{
    char ch = 0;
    printf("Enter quadratic equation coefficients a, b, c: \n");

    while (scanf("%f %f %f", a, b, c) != 3) {
        printf("incorrect enter, try again\n");
        clearBuff();
        }
}

bool isEqual(float num1, float num2)
{
 return(fabs(num1 - num2) < EPSILON);
}

void linear(float b, float c, float *answ1_pt, int *rootcnt_pt)
{
    if (isEqual(b, 0)) {
        fprintf(stderr, "nonlinear\n");

        if (isEqual(c, 0)) {
            *rootcnt_pt = INF_ROOTS;

        } else {
            *rootcnt_pt = 0;
        }
    } else {
        fprintf(stderr, "linear\n");
        *rootcnt_pt = 1;
        *answ1_pt = -c / b;

    }


}

void tester(float answ1, float answ2, float res1, float res2, int i)
{
    if ((isEqual(res1, answ1) && isEqual(res2, answ2))||(isEqual(res2, answ1) && isEqual(res1, answ2))) {
            printf("test #%d is passed\n", i+1);

        }else {
            printf("test #%d is failed\n", i+1);

            if (isEqual(res1, res2)) {
                printf("expected solution is %f.\n", res1);

            } else {
                printf("expected solutions are %f, %f\n", res1, res2);
            }
        }
}

void tests() {
    float a = NAN, b = NAN, c = NAN, answ1 = NAN, answ2 = NAN, res1 = NAN, res2 = NAN;
    int rootcnt = 0, rescnt = 0, testCount = 0;

    FILE *pIn = NULL;
    pIn = fopen("tests.txt", "r");

    assert(pIn != NULL);

    fscanf(pIn, "%d", &testCount);

    assert(testCount != 0);

    fprintf(stderr, "there are %d tests in total\n\n", testCount);

    for (int i = 0; i < testCount; i++) {
        fscanf(pIn,"%f %f %f %d", &a, &b, &c, &rescnt);

        if (rescnt == 0) {
            res1 = res2 = 0;

        } else if (rescnt == 1) {
            fscanf(pIn, "%f", &res1);
            res2 = res1;
        }else {
            fscanf(pIn, "%f %f", &res1, &res2);

        }

        solver(a, b, c, &answ1, &answ2, &rootcnt);
        printAnsw(answ1, answ2, rootcnt);
        tester(answ1, answ2, res1, res2, i);

        printf("***********************\n");

    }
    fclose(pIn);
    return;
}

void clearBuff()
{
    char ch = 0;
    while((ch = getchar()) != '\n')
    continue;

}
