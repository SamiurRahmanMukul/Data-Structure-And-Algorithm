/**
    </> Single LinkedList Length Calculate </>
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

// function prototype call
void getLength();
void insertNewNode();
void traverseElements();

int main() {
    // STEP-1: Insert new node at single linkedList
    insertNewNode();
    traverseElements();

    // STEP-2: Calculate length in single linkedList
    getLength();

    return 0;
}

// make a function to calculate single linkedList length
void getLength() {
    int count=0;
    temp = head;

    while(temp != 0) {
        count++;
        temp = temp ->next;
    }

    printf("\n\n\t Length of single LinkedList = %d \n", count);
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
