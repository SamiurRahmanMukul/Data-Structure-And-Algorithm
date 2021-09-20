/**
    </> Single LinkedList Deletion </>
        1. Delete from beginning
        2. Delete from end
        3. Delete from specific position
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *temp;

// function prototype call
void deleteAtBeg();
void deleteAtEnd();
void deleteAtSpecificPoss();

int main() {
    int pos;
    printf("When you are delete element at linkedList? \n\t Delete beginning to enter: 1 \n\t Delete end to enter:  2 \n\t Delete at specific to enter: 3 \n\t No deletion to exit: 0 \n\t Please enter you decision: ");
    scanf("%d", &pos);

    switch(pos) {
    case 1: {
        // deleteAtBeg();
        printf("\n\t Delete at beginning. \n");
        break;
    }
    case 2: {
        // deleteAtEnd();
        printf("\n\t Delete at end. \n");
        break;
    }
    case 3: {
        // deleteAtSpecificPoss();
        printf("\n\t Delete at specific position. \n");
        break;
    }
    default: {
        printf("\n\t Ohh! You are wrong response. Try to again thanks \n");
    }

    }

    return 0;
    getch();
}

/// delete element in single LinkedList at beginning
void deleteAtBeg() {
    //
}

/// delete element in single LinkedList at end
void deleteAtEnd() {
    //
}

/// delete element in single LinkedList at specific position
void deleteAtSpecificPoss() {
    //
}
