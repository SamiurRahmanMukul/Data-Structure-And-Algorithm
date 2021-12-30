/**
    <> IMPLEMENTAITION OF DOUBLY LINKEDLIST <>
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode;

// function prototype called
void createDoublyLinkedlist();
void displayDLL();

int main() {
    // call function to add elements of doubly linkedlist
    createDoublyLinkedlist();

    // call function print all elements of doubly linkedlist
    displayDLL();
    return 0;
}

// make a function to add elements doubly linkedlist
void createDoublyLinkedlist() {
    struct node *temp;
    head = 0;
    int chose = 1;

    while(chose) {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("\n\t Please enter element of doubly linkedlist: ");
        scanf("%d", &newnode ->data);

        newnode ->prev = 0;
        newnode ->next = 0;

        if(head == 0) {
            head = temp = newnode;
        } else {
            temp ->next = newnode;
            newnode ->prev = temp;
            temp = newnode;
        }

        printf("\n\t Do you add more element of doubly linkedlist? Enter: 1 or Exit: 0 \n\t\t Enter decision: ");
        scanf("%d", &chose);
    }
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
