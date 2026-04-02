/*Q1)  Write a program to input elements into two arrays A[5] and B[5]. Input
the elements in ascending order and then merge their values into a resultant
array C[10] in sorted manner using UDF.*/
#include <stdio.h>
void merge(int A[], int B[], int C[], int n)
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }

    while (i < n)
    {
        C[k++] = A[i++];
    }

    while (j < n)
    {
        C[k++] = B[j++];
    }
}

int main()
{
    int A[5], B[5], C[10];

    printf("Enter 5 elements for array A (ascending order):\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter 5 elements for array B (ascending order):\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &B[i]);
    }

    merge(A, B, C, 5);

    printf("Merged sorted array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", C[i]);
    }

    return 0;
}