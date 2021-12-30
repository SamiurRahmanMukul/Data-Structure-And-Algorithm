/**
    </> Insertion Of Circular LinkedList </>
        1. Insert data at Beginning
        2. Insert data at End
        3. Insert data at Specific Position
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
int getLengthOfCLL();
void insertAtBeg();
void insertAtEnd();
void insertAtPos();

int main() {
    int conti = 1;

    // STEP-1: firstly insert elements of circular linkedlist
    circularLL();
    displayCLL();

    // STEP-2: insert elements of circular linkedlist at specific position
    while(conti) {
        int chose;
        printf("\nPlease enter position when you insert elements of circular linkedlist? \n\t If insert at Beginning: 1 \n\t Or insert at End: 2 \n\t Or insert at Specific Position: 3 \n\t Enter your decision here: ");
        scanf("%d", chose);

        switch(chose) {
        case 1: {
            // insert data at beginning of circular linkedlist
            insertAtBeg();
            break;
        }
        case 2: {
            // insert data at end of circular linkedlist
            insertAtEnd();
            break;
        }
        case 3: {
            // insert data at beginning of circular linkedlist
            insertAtPos();
            break;
        }
        default: {
            printf("\nSorry! Incorrect response. Try to again. Thanks");
        }
        }

        printf("\nDo you insert more elements of circular linkedlist? \n\t To enter: 1 \n\t Or exit: 0 \n\t Enter your decision here: ");
        scanf("%d", conti);

        if(conti == 0) {
            printf("\nProgram terminate successfully.");
            break;
        }
    }

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

// make a function to calculate circular linkedList length
int getLengthOfCLL() {
    int count=0;
    struct node *temp;

    temp = head;

    while(temp != 0) {
        count++;
        temp = temp ->next;
    }

    return count;
}

// make a function to insert data at beginning of circular linkedlist
void insertAtBeg() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nPlease enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if(tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

// make a function to insert data at end of circular linkedlist
void insertAtEnd() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nPlease enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

// make a function to insert data at end of circular linkedlist
void insertAtPos() {
    int pos, l, i=1;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nPlease enter position when you insert data: ");
    scanf("%d", &pos);

    l = getLengthOfCLL(); // called function to get length of circular linkedlist

    if(pos<0 || pos>l) {
        printf("\nSorry! Invalid position.");
    } else if (pos == 1) {
        insertAtBeg(); // called function to insert data at beginning
    } else {
        printf("\nPlease enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp = tail->next;

        while(i<pos-1) {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}
