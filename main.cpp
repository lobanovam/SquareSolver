#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    float disc = 0.0;
    char ch = '0';
    printf("This program solves the equations of this type: ");
    printf("a*x^2 + b*x + c = 0\n");
    printf("Enter quadratic equation coefficients a, b, c: \n");


    while (scanf("%f %f %f", &a, &b, &c) != 3) {
        printf("incorrect enter, try again\n");
        while ((ch = getchar()) != '\n') {
        continue;
        }
    }

    if (a == 0 && b == 0) {
        if (c != 0) {
            printf("%f = 0 has no solutions\n", c);
            return 0;
        } else {
            printf("there are an infinite number of solutions\n");
            return 0;
        }
    }
    if (a == 0) {
        printf("it's a linear equation\n");
        printf("answer is %f\n", -c/b);


    } else {
        printf("it's a quadratic equation\n");
        if ((disc = b*b - 4*a*c) < 0) {
            printf("there are no real solutions\n");
            return 0;

        } else if (disc == 0) {
            printf("oh, full square!\n");
            printf("answer is %f\n", -b/(2*a));

        } else {
            printf("first answer is %f, second is %f\n",
            (-b - sqrt(disc))/(2*a), (-b + sqrt(disc))/(2*a) );
        }

    }
    printf("Hope that you are satisfied\n");
    return 0;
}