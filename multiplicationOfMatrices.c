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
            case 1 :
                {
                    int array1[3][3] , array2[3][3], sum[3][3] ,
    *ptrToArray1 =  &array1[0][0] , *ptrToArray2 =  &array2[0][0] , *ptrToSum = &sum[0][0];
    // taking first matrix input
    printf("Enter first matrix : \n");
    for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0; j  < 3 ; j++)
                {
                    printf("Enter a%d%d : ",i+1,j+1);
                    scanf("%d",&array1[i][j]);
                }
        }
    // taking second matrix input
    printf("Enter second matrix : \n");

    for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0; j  < 3 ; j++)
                {
                    printf("Enter a%d%d : ",i+1,j+1);
                    scanf("%d",&array2[i][j]);
                }
        }
    //ading matrices
    for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0; j  < 3 ; j++)
                {
                    sum[i][j] = *( ptrToArray1+(i*3) + j ) + *( ptrToArray1+(i*3) + j ) ;
                }
        }
    // displaying addition matrix
    for(int i = 0 ; i < 3 ;i++)
        {
            for(int j = 0 ; j  < 3 ;j++)
                {
                    printf("%d\t",sum[i][j]);
                }
            printf("\n");
        }
                    break;
                }
            case 2 :
                {
                     int array1[3][3] , array2[3][3], multiplication[3][3]  , 
    *ptrToArray1 =  &array1[0][0] , *ptrToArray2 =  &array2[0][0] , *ptrToMultiplication = &multiplication[0][0];
    // initializing multiplication matrix with zero
    for(int i = 0 ; i < 3 ;i++)
    {
        for(int j = 0 ; j < 3 ;j++)
        {
            multiplication[i][j] = 0 ;

        }
    }
    // taking first matrix input
    printf("Enter first matrix : \n");
    for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0; j  < 3 ; j++)
                {
                    printf("Enter a%d%d : ",i+1,j+1);
                    scanf("%d",&array1[i][j]);
                }
        }
    // taking second matrix input
    printf("Enter second matrix : \n");
    for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0; j  < 3 ; j++)
                {
                    printf("Enter a%d%d : ",i+1,j+1);
                    scanf("%d",&array2[i][j]);
                }
        }
    // multiplication of matrices
    for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        multiplication[i][j] = multiplication[i][j] + ((*( ptrToArray1+(i*3) + k )) * (*( ptrToArray2+(k*3) + j )));
                    }
                }
            }
    // printing Multiplication Matrix
    printf("Multiplication Matrix is :\n");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%d ", multiplication[i][j]);
                }
                printf("\n");
            }
                    break;
                }
        }
    return 0;
}
