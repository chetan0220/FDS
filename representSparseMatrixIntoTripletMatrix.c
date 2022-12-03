#include <stdio.h>

int main()
{
    int mat[100][100] , rows ,cols , nonZerosCount = 0 ;
    printf("No of rows : ");
    scanf("%d",&rows);
    printf("No of columns : ");
    scanf("%d",&cols);
    // input matrix and count non zero values
    for(int i = 0 ; i < rows; i++)
    {
        for(int j = 0 ; j < cols; j++)
        {
            scanf("%d" , &mat[i][j]);
            if(mat[i][j] != 0)
            {
                nonZerosCount++;
            }
        }
    }
    // creating triplet Matrix
    int tripletMatrix[nonZerosCount][3] , p = 0;
    for(int i = 0 ; i < rows; i++)
    {
        for(int j = 0 ; j < cols; j++)
        {
           
            if(mat[i][j] != 0)
            {
                tripletMatrix[p][0] = i ;
                tripletMatrix[p][1] = j ;
                tripletMatrix[p][2] = mat[i][j] ;
                p++;
            }
        }
    }
    // displaying triplet Matrix
    for(int i = 0 ; i < nonZerosCount ;i++)
    {
        for(int j = 0 ; j < 3 ;j++)
        {
            printf("%d  ",tripletMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
