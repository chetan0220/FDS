#include <stdio.h>

int main() 
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
    return 0;
}
