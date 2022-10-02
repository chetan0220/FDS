/*

Pass two parameters to function as(start and end), and display all prime numbers between two
Intervals

*/

#include <stdio.h>
int isPrime(int n)
{
    int j, flag = 1;

    for (j = 2; j <= n / 2; ++j)
    {

        if (n % j == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{

    int num1, num2, i, flag;

    printf("Enter start and end: ");
    scanf("%d %d", &num1, &num2);

    printf("Prime numbers between %d and %d are: ", num1, num2);
    for (i = num1 + 1; i < num2; ++i)
    {
        flag = isPrime(i);
        if (flag == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
