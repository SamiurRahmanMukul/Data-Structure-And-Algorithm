/**
    <> REVERSE ELEMENT OF DOUBLY LINKEDLIST <>
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

// function prototype called
void createDLL();
void reverseDLL();
void displayDLL();

int main() {
    // insert element of doubly linkedlist
    createDLL();
    displayDLL(); // print all element after reverse doubly linkedlist

    // reverse element of doubly linkedlist
    reverseDLL();
    displayDLL(); // print all element before reverse doubly linkedlist

    return 0;
}

// make a function to create linkedlist
void createDLL() {
    struct node *newnode;
    head = 0;
    int chose = 1;

    while(chose) {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("\n\t Please enter element of doubly linkedlist: ");
        scanf("%d", &newnode ->data);

        newnode ->prev = 0;
        newnode ->next = 0;

        if(head == 0) {
            head = tail = newnode;
        } else {
            tail ->next = newnode;
            newnode ->prev = tail;
            tail = newnode;
        }

        printf("\n\t Do you add more element of doubly linkedlist? Enter: 1 or Exit: 0 \n\t\t Enter decision: ");
        scanf("%d", &chose);
    }
}

// make a function to reverse element of doubly linkedlist
void reverseDLL() {
    struct node *current, *nextnode;
    current = head;

    while (current != 0) {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
    }

    current = head;
    head = tail;
    tail = current;
}

// make a function to print / traverse doubly linkedlist elements
void displayDLL() {
    struct node *temp;
    temp = head;
    int count=0;

    // traverse / print elements of linkedList
    temp = head;
    while (temp != 0) {
        printf("\n\t Linked elements of [%d] = %d", count+1, temp -> data);
        temp = temp -> next;
        count ++;
    }
    printf("\n");
}
