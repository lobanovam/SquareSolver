      //cd /d "D:\Program files\cProjects\quadratic1" //g++git-auto main.cpp solver.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void getCoef(float * u, float * v, float * d);
void linear(float b, float c, float * u);
void quadratic(float a, float b, float c, float * u, float * v, int * d);
void printAnsw(float answ1, float answ2, int option);
void solver(float a, float b, float c, float*ans1, float*ans2, int*u);
void tester(float answ1, float answ2, float res1, float res2, int i);
bool isEqual(float num1, float num2);
void tests();


int main(int args, char * argv[])
{

    float a = 0.0, b = 0.0, c = 0.0, answ1 = 0.0, answ2 = 0.0;
    int option = 0, resct = 0, choice = 0, ch = '0';



    printf("This program solves the equations of this type: ");
    printf("a*x^2 + b*x + c = 0\n");

    printf("press 1 to input coefficients yourself, press 2 to run tests\n");
    while((scanf("%d", &choice) !=1) || (choice != 1 && choice != 2)) {
        printf("please press 1 or 2\n");
        while((ch = getchar()) != '\n')
        continue;
    }

    if(choice == 1) {
        getCoef(&a, &b, &c);
        solver(a, b, c, &answ1, &answ2, &option);
        printAnsw(answ1, answ2, option);

    }else {
        tests();
    }
    printf("Hope that you are satisfied\n");
    return 0;
}



















