/**
    </> Single LinkedList Reverse </>
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp, *prevnode, *currentnode, *nextnode;

// function prototype call
void reverseSingleLinkedList();
void insertNewNode();
void traverseElements();

int main() {
    // STEP-1: Insert new node in single linkedList & traverse
    insertNewNode();

    printf("\n ===> Printing all element in single linkedList <=== \n");
    traverseElements();

    // STEP-2: Reverse single linkedList & traverse
    int chose;
    printf("\n\n\t Are you reverse single linkedList? Enter: 1 or Exit enter: 0 \n\t Enter decision: ");
    scanf("%d", &chose);

    if(chose == 1) {
        reverseSingleLinkedList();

        printf("\n ===> Reverse single linkedList all element print <=== \n");
        traverseElements();
    }
    traverseElements();

    return 0;
}

// create a reverseSingleLinkedList() function to reverse single linkedList
void reverseSingleLinkedList() {
    prevnode = 0;
    currentnode = nextnode = head;

    while(nextnode != 0) {
        nextnode = nextnode ->next;
        currentnode ->next = prevnode;
        currentnode = nextnode;
    }

    head = prevnode;
}

// create a insertNewNode() function to insert elements on linkedList
void insertNewNode() {
    printf("\n ===> Insert New Node <=== \n");

    head=0;
    int chose=1, count=0; /// here 'count' is size of linkedList

    while(chose) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter elements of linkedList: ");
        scanf("%d", &newnode -> data);
        newnode -> next = 0;

        if (head == 0) {
            head = temp = newnode;
        } else {
            temp -> next = newnode;
            temp = newnode;
        }

        printf("\nDo you continue add elements to linkedList? \n\t(If exit enter: 0 or Enter: 1): ");
        scanf("%d", &chose);
        if (chose == 0) {
            break;
        }
    }
}

// traverse / print elements of linkedList
void traverseElements() {
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
