/**
    </> Implementation Of Circular LinkedList </>
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// function prototype called
void circularLL();
void displayCLL();

int main() {
    circularLL(); // called function to create new elements of circular linkedlist
    displayCLL(); // called function to print all elements of circular linkedlist

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

// make a function to print all elements at circular linkedlist
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
