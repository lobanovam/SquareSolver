#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "solver_util.h"
#include "assert.h"
/**@brief minimal distance between two floats*/
const double EPSILON = 1E-7;


void quadratic(float *s, int *rootcnt_pt)
{
    ASSERT(s != nullptr);
    ASSERT(rootcnt_pt != nullptr);

    float a = *s;
    float b = *(s+1);
    float c = *(s+2);

    if (isEqual(*s, 0)) {
            linear(s+1, rootcnt_pt);
            *(s+3) = *(s+4);

    } else {
        float disc = b*b - 4*a*c;

        if (disc < 0) {
            fprintf(stderr, "disc < 0\n");
            *rootcnt_pt = 0;
            *(s+3) = *(s+4) = 0;

        } else if (isEqual(disc, 0)) {
            fprintf(stderr, "disc = 0\n");
            *(s+3) = *(s+4) = -b / (2*a);
            *rootcnt_pt = 1;

        } else {
            float sqrt_disc = sqrt(disc);
            fprintf(stderr, "disc > 0\n");
            *(s+3) = (-b + sqrt_disc) / (2*a);
            *(s+4) = (-b - sqrt_disc) / (2*a);
            *rootcnt_pt = 2;
        }
    }
}

void linear(float *s, int *rootcnt_pt)
{
    ASSERT(s != nullptr);
    ASSERT(rootcnt_pt != nullptr);
    float b = *s;           /**bx + c = 0 */
    float c = *(s+1);

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
        *(s+3) = *(s+4) = -c / b;
    }
}

bool isEqual(float num1, float num2)
{
 return(fabs(num1 - num2) < EPSILON);
}





