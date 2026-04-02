/*Q1) Write a program to store N numbers using dynamic memory allocation and
then find the largest element using UDF. */
#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int *arr, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n);

    printf("Largest element = %d\n", max);

    free(arr);

    return 0;
}