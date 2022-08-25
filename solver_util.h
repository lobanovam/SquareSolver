#ifndef SOLVER_UTIL_H_INCLUDED
#define SOLVER_UTIL_H_INCLUDED

/**@brief solves linear equations, private func, being called from solver()
    @param s pointer to array
*/
void linear(float *s, int *rootcnt_pt);

/**@brief solves quadratic equations, private func, being called from solver() */
void quadratic(float *s, int *rootcnt_pt);

/**@brief comparing two float numbers using EPSILON
   @return 1 if numbers are equal, 0 if opposite*/
bool isEqual(float num1, float num2);

const int INF_ROOTS = 3;

#endif // SOLVER_UTIL_H_INCLUDED
