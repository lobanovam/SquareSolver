#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

/**@brief gets coefs from user (keyboard input)*/
void getCoef(float *a, float *b, float *c);

/**@brief printing solutions*/
void printAnsw(float answ1, float answ2, int rootct);

/**@brief being called from main, run tests from file "tests.txt"*/
void tests();

/**@brief clearing buffer after scanf()*/
void clearBuff();

/**@brief being called from tests(), comparing expected and calculated results*/
void tester(float answ1, float answ2, float res1, float res2, int i);



#endif // UTIL_H_INCLUDED
