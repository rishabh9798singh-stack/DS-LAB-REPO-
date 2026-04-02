/*Q1) Write a program using C to create a stack  of numbers and perform using
UDF:
(i) push opera on (ii) pop opera on (iii) display opera on */
#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;
void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", stack[top]);
    top--;
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}