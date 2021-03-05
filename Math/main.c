#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int addition;
    int subtraction;
    long multiplication;
    double division;

    printf("What is the first number? ");
    scanf("%d", &num1);

    printf("What is the second number? ");
    scanf("%d", &num2);

    addition = num1 + num2;
    subtraction = num1 - num2;
    multiplication = num1 * num2;
    division = (double)num1 / (double)num2;

    printf("%d + %d = %d\n", num1, num2, addition);
    printf("%d - %d = %d\n", num1, num2, subtraction);
    printf("%d * %d = %ld\n", num1, num2, multiplication);
    printf("%d / %d = %f\n", num1, num2, division);

    return 0;
}
