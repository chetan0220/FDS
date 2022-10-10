
#include <stdio.h>

int main()
{
    int operation;
    printf("For Addition type 1\n");
    printf("For Multiplication type 2\n");
    printf("For saddle point type 3\n");
    printf("For saddle point using pointers type 4\n");
    printf("Enter your choice : ");
    scanf("%d", &operation);

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
          case 3 :
            {
                int i, j, k, min, max, matrix[3][3], s[2][2];
                printf("Enter matrix: \n");
                for (i = 0; i < 3; i++) 
                    {
                        for (j = 0; j < 3; j++) 
                            {
                                scanf("%d", &matrix[i][j]);
                            }
                    }

                for (i = 0; i < 3; i++) 
                    {
                        min = matrix[i][0];
                        for (j = 0; j < 3; j++) 
                            {
                                if (min >= matrix[i][j]) 
                                    {
                                        min = matrix[i][j];
                                        s[0][0] = i;
                                        s[0][1] = j;
                                    }
                            }           

                        j = s[0][1];
                        max = matrix[0][j];
                        for (k = 0; k < 3; k++) 
                            {
                                if (max <= matrix[k][j]) 
                                    {
                                        max = matrix[i][j];
                                        s[1][0] = k;
                                        s[1][1] = j;
                                    }
                            }

                        if (min == max) 
                            {
                                if (s[0][0] == s[1][0] && s[0][1] == s[1][1]) 
                                    {
                                        printf("Saddle point (%d, %d) : %d\n", s[0][0], s[0][1], max);
                                    }
                            }
                    }
              
              break;
            }
          case 4:
            {
              int i, j, k, min, max, matrix[3][3], s[2][2] , *ptrToMatrix = &matrix[0][0];
                printf("Enter matrix: \n");
                for (i = 0; i < 3; i++) 
                    {
                        for (j = 0; j < 3; j++) 
                            {
                                scanf("%d", &matrix[i][j]);
                            }
                    }

                for (i = 0; i < 3; i++) 
                    {
                        min = matrix[i][0];
                        for (j = 0; j < 3; j++) 
                            {
                                if (min >= *( ptrToMatrix+(i*3) + j )) 
                                    {
                                        min = *( ptrToMatrix+(i*3) + j );
                                        s[0][0] = i;
                                        s[0][1] = j;
                                    }
                            }           

                        j = s[0][1];
                        max = matrix[0][j];
                        for (k = 0; k < 3; k++) 
                            {
                                if (max <= *( ptrToMatrix+(k*3) + j)) 
                                    {
                                        max = *( ptrToMatrix+(i*3) + j );
                                        s[1][0] = k;
                                        s[1][1] = j;
                                    }
                            }

                        if (min == max) 
                            {
                                if (s[0][0] == s[1][0] && s[0][1] == s[1][1]) 
                                    {
                                        printf("Saddle point (%d, %d) : %d\n", s[0][0], s[0][1], max);
                                    }
                            }
                    }
              



              break;
            }
        }
    return 0;
}

