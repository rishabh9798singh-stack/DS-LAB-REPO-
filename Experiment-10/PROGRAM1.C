/*Q1) Write a program to create a single linked list for storing the N cricket 
player details having member’s player name, team name and ba ng average. 
Display only those players informa on whose ba ng average>=50*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char player[50];
    char team[50];
    float avg;
    struct Node* next;
};

struct Node* head = NULL;

void createNode(char p[], char t[], float a) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->player, p);
    strcpy(newNode->team, t);
    newNode->avg = a;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->avg >= 50) {
            printf("Player: %s\n", temp->player);
            printf("Team: %s\n", temp->team);
            printf("Average: %.2f\n\n", temp->avg);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    char p[50], t[50];
    float a;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %f", p, t, &a);
        createNode(p, t, a);
    }

    display();

    return 0;
}