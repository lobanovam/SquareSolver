#ifndef SOLVER_UTIL_H_INCLUDED
#define SOLVER_UTIL_H_INCLUDED
/**@brief solves linear equations, private func, being called from solver()*/
void linear(float b, float c, float *answ1_pt, int *rootcnt_pt);

/**@brief solves quadratic equations, private func, being called from solver() */
void quadratic(float a, float b, float c, float *answ1_pt, float *answ2_pt, int *rootcnt_pt);

/**@brief comparing two float numbers using EPSILON
   @return 1 if numbers are equal, 0 if opposite*/
bool isEqual(float num1, float num2);

/**@brief being called from main, calling quadratic or linear, universal function*/
void solver(float a, float b, float c, float *ans1, float *ans2, int *rootcnt_pt);
const int INF_ROOTS = 3;


#endif // SOLVER_UTIL_H_INCLUDED
