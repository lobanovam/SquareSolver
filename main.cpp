      //cd /d "D:\Program files\cProjects\quadratic1" //g++git-auto main.cpp solver.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void getCoef(float * u, float * v, float * d);
void linear(float b, float c, float * u);
void quadratic(float a, float b, float c, float * u, float * v, int * d);
void printAnsw(float answ1, float answ2, int option);
void solver(float a, float b, float c);
bool isEqual(float num1, float num2);


int main(int args, char * argv[])
{

    float a = 0.0, b = 0.0, c = 0.0;

    FILE *pIn = NULL;

    printf("This program solves the equations of this type: ");
    printf("a*x^2 + b*x + c = 0\n");
    printf("Enter quadratic equation coefficients a, b, c: \n");


        int testCount = 0;

        if ((pIn = fopen("tests.txt", "r")) == NULL) {
            printf("can't open file\n");
            return 0;

        } else {
        printf("file is opened\n");
        }

    fscanf(pIn, "%d", &testCount);
    printf("%d\n", testCount);

    for (int i = 0; i < testCount; i++) {
        fscanf(pIn, "%f %f %f", &a, &b, &c);
        solver(a, b, c);
        printf("*********************\n");

    }
    fclose(pIn);
    //getCoef(&a, &b, &c);


    printf("Hope that you are satisfied\n");
    return 0;
}
















