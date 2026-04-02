/*Q3) Write a program to create a structure for products of a super market. Store
product no, name and cost for N products using dynamic memory allocation.
Display the products whose cost is in between 100 rupees to 1000 rupees.*/
#include <stdio.h>
#include <stdlib.h>

struct product
{
    int pno;
    char name[50];
    float cost;
};

void display(struct product *p, int n)
{
    printf("Products with cost between 100 and 1000:\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i].cost >= 100 && p[i].cost <= 1000)
        {
            printf("Product No: %d\n", p[i].pno);
            printf("Name: %s\n", p[i].name);
            printf("Cost: %.2f\n\n", p[i].cost);
        }
    }
}

int main()
{
    struct product *p;
    int n;

    printf("Enter number of products: ");
    scanf("%d", &n);

    p = (struct product *)malloc(n * sizeof(struct product));

    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("Enter product details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Product %d\n", i + 1);

        printf("Enter product no: ");
        scanf("%d", &p[i].pno);

        printf("Enter name: ");
        scanf("%s", p[i].name);

        printf("Enter cost: ");
        scanf("%f", &p[i].cost);
    }

    display(p, n);

    free(p);

    return 0;
}