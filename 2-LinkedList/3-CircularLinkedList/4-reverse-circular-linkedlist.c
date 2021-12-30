/**
    </> REVERSE A CIRCULAR LINKEDLIST </>
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

// function prototype called
void circularLL();
void displayCLL();
void reverseCLL();

int main() {
    // called function to create circular linkedlist
    circularLL();
    displayCLL();

    // reverse circular linkedlist
    reverseCLL();
    displayCLL();

    return 0;
}

// make a function to create elements of circular linkedlist
void circularLL() {
    struct node *newnode;
    head = 0;
    int chose = 1;

    while(chose) {
        struct node *newnode, *temp;
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("\nPlease enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head == 0) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        temp->next = head;

        printf("\nAre you insert more data: \n\t to Enter: 1 \n\t or Exit: 0 \n\t Enter your decision here: ");
        scanf("%d", &chose);

        if(chose == 0) {
            break;
        }
    }
}

// make a function to print all elements of circular linkedlist
void displayCLL() {
    struct node *temp;

    if(head == 0) {
        printf("\nSorry! Your linkedlist is empty.");
    } else
        temp = head;

    printf("\n=====> All Elements Of Circular LinkedList <=====");
    while(temp->next != head) {
        printf("\n\t\t %d",temp-> data);
        temp = temp->next;
    }
    printf("\n\t\t %d", temp->data);
}

// make a function to reverse a circular linkedlist
void reverseCLL() {
    struct node *current, *prev, *nextnode;
    current = tail->next;

    if(tail == NULL) {
        printf("\nLinkedlist is empty.");
    } else {
        while(current != tail) {
            prev = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prev;
        }

        nextnode->next = tail;
        tail = nextnode;
    }
}
