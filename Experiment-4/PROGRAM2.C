/*Q2) Write a C program to create a linear queue and perform the following
opera ons using UDF:
(i) inser on ii) dele on and iii) Traversal */
#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;

void insert()
{
    int x;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = x;
}

void deleteElement()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteElement();
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