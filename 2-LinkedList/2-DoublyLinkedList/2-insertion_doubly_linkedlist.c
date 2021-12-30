/**
    <> INSERTION OF DOUBLY LINKEDLIST <>
        1. Insert at Beginning
        2. Insert at End
        3. Insert at Specific Position
        4. Insert at After Specific Position
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
int lengthOfDLL();
void inserAtBeginning();
void insertAtEnd();
void insertAtSpecificPosition();
void insertAtAfterSpecificPosition();
void displayDLL();

int main() {
    int conti = 1;
    // STEP-1: firstly insert some elements of doubly linkedlist
    createDLL(); // call createDLL() function to add elements at doubly linkedlist
    displayDLL(); // call displayDLL() function print all elements at doubly linkedlist

    // STEP-2: insert element user define position of doubly linkedlist
    while(conti) {
        int chose;
        printf("\nWhen you insert data at LinkedList? \n\t At Beginning to enter: 1 \n\t At End to enter: 2 \n\t At Specific Position to enter: 3 \n\t At After Specific Position to enter: 4 \n\t Enter your decision here: ");
        scanf("%d", &chose);

        switch(chose) {
        case 1: {
            // insert data linkedlist at beginning
            inserAtBeginning();
            break;
        }
        case 2: {
            // insert data linkedlist at end
            insertAtEnd();
            break;
        }
        case 3: {
            // insert data linkedlist at specific position
            insertAtSpecificPosition();
            break;
        }
        case 4: {
            // insert data linkedlist at after specific position
            insertAtAfterSpecificPosition();
            break;
        }
        default: {
            printf("\nSorry! Invalid response. Try to again. Thanks");
        }
        }

        printf("\nDo you insert more data at linkedlist? \n\t To enter: 1 \n\t or Exit: 0 \n\t Enter here your decision: ");
        scanf("%d", &conti);

        if(conti == 0) {
            printf("\nProgram terminate successfully.");
            break;
        }
    }

    displayDLL(); // call displayDLL() function print all elements at doubly linkedlist

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

// make a function to calculate length of doubly linkedlist
int lengthOfDLL() {
    struct node *temp;

    int count=0;
    temp = head;

    while(temp != 0) {
        count++;
        temp = temp ->next;
    }

    return count;
}

// make a function to insert element at beginning in doubly linkedlist
void inserAtBeginning() {
    struct node *newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    printf("\n\t Please enter element of doubly linkedlist: ");
    scanf("%d", &newnode ->data);

    newnode ->prev = 0;
    newnode ->next = 0;

    head ->prev = newnode;
    newnode ->next = head;
    head = newnode;
}

// make a function to insert element at end in doubly linkedlist
void insertAtEnd() {
    struct node *newnode;

    newnode = (struct node*) malloc(sizeof(struct node));
    printf("\n\t Please enter element of doubly linkedlist: ");
    scanf("%d", &newnode ->data);

    newnode ->prev = 0;
    newnode ->next = 0;

    tail ->next = newnode;
    newnode ->prev = tail;
    tail = newnode;
}

// make a function to insert element at specific position in doubly linkedlist
void insertAtSpecificPosition() {
    int pos;
    int count = lengthOfDLL(); // [HERE: count = length of linkedlist]

    printf("\n\t Please enter position when you insert element: ");
    scanf("%d", &pos);

    if(count < pos) {
        printf("\n\t Sorry! your define position is invalid.");
    } else if(pos == 1) {
        inserAtBeginning();
    } else {
        struct node *newnode, *temp, *nextnode;

        temp = head;
        int i = 1;

        newnode = (struct node*) malloc(sizeof(struct node));
        printf("\n\t Please enter element of doubly linkedlist: ");

        while(i < pos - 1) {
            temp = temp ->next;
            i++;
        }

        nextnode = temp ->next;
        newnode ->next = temp ->next;
        newnode ->next->prev = newnode;
    }
}

// make a function to insert element at after specific position in doubly linkedlist
void insertAtAfterSpecificPosition() {
    int pos;
    int count = lengthOfDLL(); // [HERE: count = length of linkedlist]

    printf("\n\t Please enter position when you insert element: ");
    scanf("%d", &pos);

    if(count < pos) {
        printf("\n\t Sorry! your define position is invalid.");
    } else if(pos == 1) {
        inserAtBeginning();
    } else {
        struct node *newnode, *temp;

        temp = head;
        int i = 1;

        newnode = (struct node*) malloc(sizeof(struct node));
        printf("\n\t Please enter element of doubly linkedlist: ");

        while(i < pos) {
            temp = temp ->next;
            i++;
        }

        newnode ->prev = temp;
        newnode ->next = temp ->next;
        temp ->next = newnode;
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
