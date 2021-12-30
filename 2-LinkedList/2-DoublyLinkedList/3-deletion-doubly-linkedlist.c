/**
    <> DELETE ELEMENT OF DOUBLY LINKEDLIST <>
        1. Delete at Beginning
        2. Delete at End
        3. Delete at Specific Position
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
void displayDLL();
void deleteFormBegg();
void deleteFromEnd();
void deleteFromSpecificPoss();

int main() {
    int conti = 1;
    // STEP-1: firstly insert some elements of doubly linkedlist
    createDLL(); // call createDLL() function to add elements at doubly linkedlist
    displayDLL(); // call displayDLL() function print all elements at doubly linkedlist

    // STEP-2: insert element user define position of doubly linkedlist
    while(conti) {
        int chose;

        printf("\nPlease enter position when you delete data? \n\t If delete at Beginning: 1 \n\t Delete at End: 2 \n\t Delete  at Specific Position: 3 \n\t Enter your decision here: ");
        scanf("%d", &chose);

        switch(chose) {
        case 1: {
            // delete element at beginning
            deleteFormBegg();
            break;
        }
        case 2: {
            // delete element at end
            deleteFromEnd();
            break;
        }
        case 3: {
            // delete element at specific position
            deleteFromSpecificPoss();
            break;
        }
        default: {
            printf("\nSorry! Invalid response. Try to again. Thanks");
        }
        }

        printf("\nDo you delete more data at linkedlist? \n\t To enter: 1 \n\t or Exit: 0 \n\t Enter here your decision: ");
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

// make a function to delete element of doubly linkedlist at beginning
void deleteFormBegg() {
    struct node *temp;

    if(head == 0) {
        printf("\nLinkedList is empty. First insert data then try to again. Thanks");
    } else {
        temp =  head;
        head = head ->next;
        head ->prev = 0;
        free(temp);
    }
}

// make a function to delete element of doubly linkedlist at end
void deleteFromEnd() {
    struct node *temp;

    if(tail == 0) {
        printf("\nLinkedList is empty. First insert data then try to again. Thanks");
    } else {
        temp = tail;
        tail ->prev->next = 0;
        tail = tail->prev;
        free(temp);
    }
}

// make a function to delete element of doubly linkedlist at specific position
void deleteFromSpecificPoss() {
    int pos, i = 1;
    struct node *temp;
    temp = head;

    printf("\nPlease enter position when you delete element: ");
    scanf("%d", &pos);

    while(i < pos) {
        temp = temp ->next;
        i++;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->next;
    free(temp);
}
