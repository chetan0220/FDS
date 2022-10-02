/*

To simulate a simple calculator that performs basic tasks such as addition, subtraction,
multiplication, and division.

*/

#include <stdio.h>
#include <math.h>

int addition(int a, int b)
{
    return a + b;
}
int subtraction(int a, int b)
{
    return a - b;
}
int multiplication(int a, int b)
{
    return a * b;
}
float division(float a, float b)
{
    return a / b;
}
int main()

{
    int num1, num2, operation;
    printf("\t\t$ CALCULATOR $\n\n");
    printf("For Addition type 1\n");
    printf("For Subtraction type 2\n");
    printf("For Multiplication type 3\n");
    printf("For Division type 4\n");
    printf("To exit calculator type 0\n\n");

repeat:

    printf("Enter your choice : ");
    scanf(" %d", &operation);

    switch (operation)
    {
    case 1:

        printf("Enter first number \n ");
        scanf(" %d", &num1);
        printf("Enter second number \n ");
        scanf(" %d", &num2);
        printf("Addition of entered numbers is : %d\n ", addition(num1, num2));
        break;

    case 2:
        printf("Enter first number : ");
        scanf(" %f", &num1);
        printf("Enter second number : ");
        scanf(" %f", &num2);
        printf("Subtraction of entered numbers is : %d\n ", subtraction(num1, num2));
        break;

    case 3:
        printf("Enter first number : ");
        scanf(" %d", &num1);
        printf("Enter second number : ");
        scanf(" %d", &num2);
        printf("Multiplication of entered numbers is : %d\n ", multiplication(num1, num2));
        break;

    case 4:
        printf("Enter numerator : ");
        scanf(" %d", &num1);
        printf("Enter denominator : ");
        scanf(" %d", &num2);
        printf("Division of entered numbers is : %.3f\n", division(num1, num2));
        break;

    case 0:
        return 0;

    default:
        printf(":( Enter valid choice \n");
    }
    goto repeat;
    return 0;
}