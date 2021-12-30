/**
    </> DELETION OF CIRCULAR LINKEDLIST </>
        1. Delete Element At Beginning
        2. Delete Element At End
        3. Delete Element At Specific Position
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
void deleteFormBeg();
void deleteFromEnd();
void deleteFromPos();

int main() {
    int conti = 1;

    // STEP-1: firstly insert some data at circular linkedlist
    circularLL();
    displayCLL();

    // STEP-2: delete elements of circular linkedlist at specific position
    while(conti) {
        int chose;

        printf("\nPlease enter position when you delete element of circular linkedlist? \n\t If delete element at Beginning: 1 \n\t Delete at End: 2 \n\t Delete at Specific Position: 3 \n\t Enter your decision here: ");
        scanf("%d", &chose);

        switch(chose) {
        case 1: {
            // delete element at beginning
            deleteFormBeg();
            displayCLL();
            break;
        }
        case 2: {
            // delete element at end
            deleteFromEnd();
            displayCLL();
            break;
        }
        case 3: {
            // delete element at specific position
            deleteFromPos();
            displayCLL();
            break;
        }
        default: {
            printf("\nIncorrect Responce. Try to again. Thanks");
        }
        }

        printf("\nDo you want to delete more elements of circular linkedlist? \n\t To enter: 1 \n\t Or exit: 0 \n\t Enter your decision here: ");
        scanf("%d", &chose);

        if(chose == 0) {
            printf("\nProgram terminate successfully.");
            break;
        }
    }

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

// make a function to calculate length of circular linkedList
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

// make a function to delete element of circular linkedlist at beginning
void deleteFormBeg() {
    struct node *temp;
    temp = tail->next;

    if(tail == 0) {
        printf("\nLinkedList is empty.");
    } else if(temp->next == temp) {
        tail = 0;
        free(temp);
    } else {
        tail->next = temp->next;
        free(temp);
    }
}

// make a function to delete element of circular linkedlist at end
void deleteFromEnd() {
    struct node *current, *previous;
    current = tail->next;

    if(tail == 0) {
        printf("\nLinkedList is empty.");
    } else if(current->next == current) {
        tail = 0;
        free(current);
    } else {
        while(current->next = tail->next) {
            previous = current;
            current = current->next;
        }

        previous->next = tail->next;
        tail = previous;
        free(current);
    }
}

// make a function to delete element of circular linkedlist at specific position
void deleteFromPos() {
    struct node *current, *nextnode;
    int pos, i = 1, l;

    printf("\nPlease enter position: ");
    scanf("%d", &pos);

    l = getLengthOfCLL(); // get length of circular linkedlist

    if(pos<1 || pos>l) {
        printf("\nInvalid position.");
    } else if(pos == 1) {
        deleteFormBeg(); // called function to delete element at beginning
    } else {
        while(i<pos - 1) {
            current = current->next;
            i++;
        }

        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
}
