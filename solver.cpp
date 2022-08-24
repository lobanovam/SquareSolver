#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "solver_util.h"
#include "assert.h"
/**@brief minimal distance between two floats*/
const double EPSILON = 1E-7;


void quadratic(float a, float b, float c, float *answ1_pt , float *answ2_pt, int *rootcnt_pt)
{
    ASSERT(answ1_pt != nullptr);
    ASSERT(answ2_pt != nullptr);
    ASSERT(rootcnt_pt != nullptr);
    ASSERT(answ1_pt != answ2_pt);
    ASSERT(a != NAN);
    ASSERT(b != NAN);
    ASSERT(c != NAN);
    ASSERT(!isEqual(a, 0));

    float disc = b*b - 4*a*c;
    if (disc < 0) {
        fprintf(stderr, "disc < 0\n");
        *rootcnt_pt = 0;
        *answ1_pt = *answ2_pt = 0;

    } else if (isEqual(disc, 0)) {
        fprintf(stderr, "disc = 0\n");
        *answ1_pt = *answ2_pt = (-b / (2*a));
        *rootcnt_pt = 1;

    } else {
        float sqrt_disc = sqrt(disc);
        fprintf(stderr, "disc > 0\n");
        *answ1_pt = (-b + sqrt_disc) / (2*a);
        *answ2_pt = (-b - sqrt_disc) / (2*a);
        *rootcnt_pt = 2;
    }
}

void solver(float a, float b, float c, float *answ1_pt, float *answ2_pt, int *rootcnt_pt )
{
    if (isEqual(a, 0)) {
        linear(b, c, answ1_pt, rootcnt_pt);
        *answ2_pt = *answ1_pt;
    } else {
        quadratic(a, b, c, answ1_pt, answ2_pt, rootcnt_pt);
    }
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

bool isEqual(float num1, float num2)
{
 return(fabs(num1 - num2) < EPSILON);
}





