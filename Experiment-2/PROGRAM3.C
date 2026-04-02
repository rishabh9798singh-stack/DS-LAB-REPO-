/*Q3) Write a program to input elements into a 4X4 matrix, check it for sparse or
not. If sparse then store the non-zero elements into an alternate matrix and then
display it using UDF. */
#include <stdio.h>
void checkSparse(int a[4][4])
{
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
                count++;
        }
    }

    if (count > (4 * 4) / 2)
    {
        printf("Matrix is sparse\n");

        int b[16][3], k = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (a[i][j] != 0)
                {
                    b[k][0] = i;
                    b[k][1] = j;
                    b[k][2] = a[i][j];
                    k++;
                }
            }
        }

        printf("Row Col Value\n");
        for (int i = 0; i < k; i++)
        {
            printf("%d   %d   %d\n", b[i][0], b[i][1], b[i][2]);
        }
    }
    else
    {
        printf("Matrix is not sparse\n");
    }
}

int main()
{
    int a[4][4];

    printf("Enter elements of 4x4 matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    checkSparse(a);

    return 0;
}