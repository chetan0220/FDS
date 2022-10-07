#include <stdio.h>
int main()
{
	int i, j, k, m, n, min, max,s[2][2];
	int matrix[3][3];
	printf("Input the matrix : ");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < m; j++)
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
	for (k = 0; k < m; k++)
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
			printf("Saddle point (%d, %d) : %d",s[0][0], s[0][1], max);
		}
	}
}
	return 0;
}
