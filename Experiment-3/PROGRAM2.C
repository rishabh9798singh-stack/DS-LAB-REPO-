/*Q2) Write a C program to create a structure called student to store your rollno,
name, age. Create an array to input 5 students data and then create an UDF to
display details where age>=20.  */
#include <stdio.h>

struct student
{
    int rollno;
    char name[50];
    int age;
};

void display(struct student s[], int n)
{
    printf("Students with age >= 20:\n");
    for (int i = 0; i < n; i++)
    {
        if (s[i].age >= 20)
        {
            printf("Roll No: %d\n", s[i].rollno);
            printf("Name: %s\n", s[i].name);
            printf("Age: %d\n\n", s[i].age);
        }
    }
}

int main()
{
    struct student s[5];

    printf("Enter details of 5 students:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Student %d\n", i + 1);

        printf("Enter roll no: ");
        scanf("%d", &s[i].rollno);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter age: ");
        scanf("%d", &s[i].age);
    }

    display(s, 5);

    return 0;
}