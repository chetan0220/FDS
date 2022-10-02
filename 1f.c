/*

Represent matrix using two-dimensional arrays and perform the following operations without
using pointers: i. Addition ii. multiplication

*/

#include <stdio.h>

int main()

{
    int operation;
    printf("For Addition type 1\n");
    printf("For Multiplication type 2\n");
    printf("Enter your choice : ");
    scanf(" %d", &operation);

    switch (operation)
    {
        case 1:
        {
            int r1, c1, r2, c2, i, j;

            printf("Enter the number of rows of first matrix :\n");
            scanf("%d", &r1);
            printf("Enter the number of columns of first matrix :\n");
            scanf("%d", &c1);

            printf("Enter the number of rows of second matrix :\n");
            scanf("%d", &r2);
            printf("Enter the number of columns of second matrix :\n");
            scanf("%d", &c2);

            int mat_1[r1][c1], mat_2[r2][c2], sum[r1][c1];

            if (r1 == r2 && c1 == c2)
            {

                printf("First matrix :\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        printf("Enter a%d%d :\n", i + 1, j + 1);
                        scanf("%d", &mat_1[i][j]);
                    }
                }

                printf("Second matrix :\n");
                for (i = 0; i < r2; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        printf("Enter a%d%d :\n", i + 1, j + 1);
                        scanf("%d", &mat_2[i][j]);
                    }
                }

                printf("Sum is :\n");
                for (i = 0; i < r2; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        sum[i][j] = mat_1[i][j] + mat_2[i][j];
                        printf("%d ", sum[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        }
        case 2:
        {
            int r1, c1, r2, c2, i, j, k, additon;

            printf("Enter the number of rows of first matrix :\n");
            scanf("%d", &r1);
            printf("Enter the number of columns of first matrix :\n");
            scanf("%d", &c1);

            printf("Enter the number of rows of second matrix :\n");
            scanf("%d", &r2);
            printf("Enter the number of columns of second matrix :\n");
            scanf("%d", &c2);

            int mat_1[r1][c1], mat_2[r2][c2], mul[r1][c2];

            if (c1 == r2)
            {
                printf("First matrix :\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        printf("Enter a%d%d :\n", i + 1, j + 1);
                        scanf("%d", &mat_1[i][j]);
                    }
                }

                printf("Second matrix :\n");
                for (i = 0; i < r2; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        printf("Enter a%d%d :\n", i + 1, j + 1);
                        scanf("%d", &mat_2[i][j]);
                    }
                }

                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        additon = 0;
                        for (k = 0; k < r2; k++)
                        {
                            additon += mat_1[i][k] * mat_2[k][j];
                            mul[i][j] = additon;
                        }
                    }
                }
            }

            printf("Multiplication Matrix is :\n");
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c2; j++)
                {
                    printf("%d ", mul[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}