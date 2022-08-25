/**

@brief This program solves quadratic (ax2 + bx + c = 0) and linear (bx + c = 0) equations.

@detailed There are two ways of using this program. Firstly, you can input coefficients
a, b and c by yourself, for this press "1" after running the program. Secondly, you can
run tests from "tests.txt" file (first 3 numbers in each line of this file are coefficients,
4th number is number of roots, 5th and 6th are roots), to run tests press "2" after running the program.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "util.h"
#include "assert.h"
#include "solver_util.h"



/**
    @param a coefficient a
    @param b coefficient b
    @param c coefficient c
    @param rootcnt number of roots
    @param choice input/tests mode (1, 2 or 3)
    @param res1 expected solution 1
    @param res2 expected solution 2
    @param testCount number of tests
    @param rescnt number of expected solutions

*/
enum choice {
    quadratic_mode = 1,
    linear_mode,
    test_mode
};

int main()
{
    float arr[10] = {0};

    int rootcnt = 0, choice = 0, coef_cnt = 0;

    printf("This program solves the equations of this type: a*x^2 + b*x + c = 0\n");
    printf("press 1 to quadr, press 2 to linear, press 3 to tests\n");

    while (scanf("%d", &choice) != 1 ||
        choice != quadratic_mode && choice != linear_mode && choice != test_mode) { /**@brief choosing the mode (1, 2 or 3)*/
        printf("please press 1, 2 or 3\n");
        clearBuff();
    }
    clearBuff();
    if (choice == test_mode) {
        tests();
    } else {
        switch(choice) {
            case(quadratic_mode): coef_cnt = 3;
                    printf("please enter 3 coeffs\n");
                    getCoef(arr, coef_cnt);
                    quadratic(arr, &rootcnt);
                    break;
            case(linear_mode): coef_cnt = 2;
                    printf("please enter 2 coeffs\n");
                    getCoef(arr, coef_cnt);
                    linear(arr, &rootcnt);
                    break;
        }

        printAnsw(arr, rootcnt);
    }
    printf("Hope that you are satisfied\n");

    return 0;
}

void printAnsw(const float *s, int rootcnt)
{
    switch(rootcnt) {
        case 0: printf("there are no real solutions\n");
            break;

        case 1:
            printf("there is only one solution, it is %f\n", *(s+3));
            break;

        case INF_ROOTS: printf("there are an infinite number of solutions\n");
            break;

        case 2: if (isEqual(*(s+3), *(s+4))) {
                    printf("one solution: %f\n", *(s+3));
                } else {
                    printf("first solution is %f, second is %f\n", *(s+3), *(s+4));
                }
    }

}

void getCoef(float *a, int coef_cnt)
{
    for (int i = 0; i < coef_cnt; i++) {
            while (scanf("%f", a+i) != 1) {
                printf("please enter a float\n");
                clearBuff();
            }
        }

        clearBuff();
}

void tester(float answ1, float answ2, float res1, float res2, int i)
{
    if ((isEqual(res1, answ1) && isEqual(res2, answ2))
     || (isEqual(res2, answ1) && isEqual(res1, answ2))) {
            printf("test #%d is passed\n", i+1);
    } else {
        printf("test #%d is failed\n", i+1);

        if (isEqual(res1, res2)) {
            printf("expected solution is %f.\n", res1);
        } else {
            printf("expected solutions are %f, %f\n", res1, res2);
        }
    }
}

 void tests() {
    float res1 = NAN, res2 = NAN, arr[10] = {};
    int rootcnt = 0, rescnt = 0, testCount = 0;

    FILE *pIn = NULL;
    pIn = fopen("tests.txt", "r");

    ASSERT(pIn != NULL);

    fscanf(pIn, "%d", &testCount);

    ASSERT(testCount != 0);

    fprintf(stderr, "there are %d tests in total\n\n", testCount);

    for (int i = 0; i < testCount; i++) {

        for (int j = 0; j < 3; j++) {
            while (fscanf(pIn, "%f", &arr[j]) != 1) {
                clearBuff();
            }
        }
        fscanf(pIn, "%d", &rescnt);

        if (rescnt == 0) {
            res1 = res2 = 0;

        } else if (rescnt == 1) {
            fscanf(pIn, "%f", &res1);
            res2 = res1;

        }else {
            fscanf(pIn, "%f %f", &res1, &res2);
        }

        quadratic(arr, &rootcnt);
        printAnsw(arr, rootcnt);
        tester(arr[3], arr[4], res1, res2, i);

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


