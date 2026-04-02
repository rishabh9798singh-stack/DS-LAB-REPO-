/*Q2) Write a program to create a double linked list for storing account details 
of bank customers such as AC no, name, balance. Store details for N bank 
account holders and find the total balance for all account holders.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int acc_no;
    char name[50];
    float balance;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void createNode(int acc, char n[], float bal) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->acc_no = acc;
    strcpy(newNode->name, n);
    newNode->balance = bal;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

float totalBalance() {
    struct Node* temp = head;
    float sum = 0;

    while (temp != NULL) {
        sum += temp->balance;
        temp = temp->next;
    }

    return sum;
}

void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("AC No: %d\n", temp->acc_no);
        printf("Name: %s\n", temp->name);
        printf("Balance: %.2f\n\n", temp->balance);
        temp = temp->next;
    }
}

int main() {
    int n, acc;
    char name[50];
    float bal;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &acc, name, &bal);
        createNode(acc, name, bal);
    }

    display();

    printf("Total Balance: %.2f\n", totalBalance());

    return 0;
}