#include <stdio.h>
int main()
{
    int m, n;
   
    printf("ENTER NO OF ROWS AND COLUMNS \n");
    scanf("%d%d", &m, &n);
     int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // max element in row
    for (int i = 0; i < m; i++)
    {
        int max = a[i][0];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        printf("MAX ELEMENT IN COLUMN %d is %d \n", i, max);
    }
    // max element in column
    for (int i = 0; i < n; i++)
    {
        int max = a[0][i];
        for (int j = 0; j < m; j++)
        {
            if (a[j][i] > max)
            {
                max = a[j][i];
            }
        }
        printf("MAX ELEMENT IN COLUMN %d is %d\n", i, max);
    }
}