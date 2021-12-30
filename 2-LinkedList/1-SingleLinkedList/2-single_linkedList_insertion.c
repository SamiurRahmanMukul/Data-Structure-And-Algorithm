/**
    </> single LinkedList insertion </>
        1. insert at beginning           --> first element
        2. insert at end                 --> last element
        3. inset at user define position --> specific position
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

// function prototype call
void insetAtStart();
void insertAtEnd();
void insertAtSpecific();
void traverseElements();

int main() {
    int pos, continous=1;

    while (continous) {
        printf("\n When you are insert elements at linkedList? \n\t insetAtStart to enter: 1 \n\t insertAtEnd to enter: 2 \n\t insertAtSpecific to enter: 3 \n\t noElementInsert to exit: 0 \n\t Please enter you decision: ");
        scanf("%d", &pos);

        if (pos == 1) {
            insetAtStart();

            printf("\n Do you insert more elements ? Enter: 1 Or exit: 0 \n\t Enter decision: ");
            scanf("%d", &continous);

            if (continous == 0) {
                printf("\n\t You'r successfully exit !");
                break;
            }
        } else if (pos == 2) {
            insertAtEnd();

            printf("\n Do you insert more elements ? Enter: 1 Or exit: 0 \n\t Enter decision: ");
            scanf("%d", &continous);

            if (continous == 0) {
                printf("\n\t You'r successfully exit !");
                break;
            }
        } else if (pos == 3) {
            insertAtSpecific();

            printf("\n Do you insert more elements ? Enter: 1 Or exit: 0 \n\t Enter decision: ");
            scanf("%d", &continous);

            if (continous == 0) {
                printf("\n\t You'r successfully exit !");
                break;
            }
        } else {
            printf("\n\t You'r successfully exit !");
            break;
        }
    }

    /// printing / traverse all LinkedList elements
    printf("\n\n\t You'r inserted all LinkedList elements:");
    traverseElements();
    return 0;
}

// create a insertAtStart() function to insert elements at beginning on linkedList
void insetAtStart() {
    printf("\n ===> Insert At Beginning <=== \n");

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\n\t Please enter element: ");
    scanf("%d", &newnode -> data);
    newnode -> next = head;
    head = newnode;
}

// create a insertAtEnd() function to insert elements at end on linkedList
void insertAtEnd() {
    printf("\n ===> Insert At End <=== \n");

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\n\t Please enter element: ");
    scanf("%d", &newnode -> data);
    newnode -> next = 0;
    temp = head;

    while(temp -> next != 0) {
        temp = temp -> next;
    }
    temp -> next = newnode;
}

// create a insertAtSpecific() function to insert elements at user define on linkedList
void insertAtSpecific() {
    printf("\n ===> Insert At Specific Position <=== \n");

    int pos, count=1, i=1;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\n\t Enter position when you insert element: ");
    scanf("%d", &pos);

    if (pos > count) {
        printf("\n\t Oops! Invalid position. Try again thanks");
    } else {
        temp = head;
        while(i < pos) {
            temp = temp -> next;
            i++;
        }

        printf("\n\t Please enter element: ");
        scanf("%d", &newnode -> data);
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

// traverse / print elements of linkedList
void traverseElements() {
    int count=0;

    // traverse / print elements of linkedList
    temp = head;
    while (temp !=0) {
        printf("\n\t Linked elements of [%d] = %d", count+1, temp -> data);
        temp = temp -> next;
        count ++;
    }
    printf("\n\t Linked elements of [%d] = %d", count+1, temp -> data);
    printf("\n");
}
