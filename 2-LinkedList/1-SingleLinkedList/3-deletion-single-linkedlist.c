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

struct node *head, *newnode, *temp;

// function prototype call
void insertNewNode();
void deleteAtBeg();
void deleteAtEnd();
void deleteAtSpecificPoss();
void traverseElements();

int main() {
    // STEP-1: insert new node
    insertNewNode();
    traverseElements();

    // STEP-2: delete node any position
    int count=1;

    while(count) {
        int pos;
        printf("Please enter position when you delete node? If delete beginning enter: 1, Delete end enter: 2, Delete at specific position enter: 3 or No delete to exit enter: 0 \n\t Enter decision: ");
        scanf("%d", &pos);

        if(pos == 1) {
            deleteAtBeg();

            printf("Do you delete more node? Enter: 1 or Exit enter: 0 \n\t Enter decision: ");
            scanf("%d", &count);

            if(count == 0) {
                break;
            }
        } else if(pos == 2) {
            deleteAtEnd();

            printf("Do you delete more node? Enter: 1 or Exit enter: 0 \n\t Enter decision: ");
            scanf("%d", &count);

            if(count == 0) {
                break;
            }
        } else if(pos == 3) {
            deleteAtSpecificPoss();

            printf("Do you delete more node? Enter: 1 or Exit enter: 0 \n\t Enter decision: ");
            scanf("%d", &count);

            if(count == 0) {
                break;
            }
        } else {
            printf("\n Something went wrong! Program terminate !!!");
            break;
        }
    }

    /// printing / traverse LinkedList elements
    traverseElements();

    return 0;
}

// delete element in single LinkedList at beginning
void deleteAtBeg() {
    printf("\n ===> Delete At Beginning <=== \n");

    temp = head;
    head = head ->next;
    free(temp);
}

// delete element in single LinkedList at end
void deleteAtEnd() {
    printf("\n ===> Delete At End <=== \n");

    struct node *prevnode;
    temp = head;

    while(temp -> next != 0) {
        prevnode = temp;
        temp = temp ->next;
    }

    if(temp == head) {
        head = 0;
    } else {
        prevnode = 0;
        free(temp);
    }
}

// delete element in single LinkedList at specific position
void deleteAtSpecificPoss() {
    printf("\n ===> Delete At Specific Position <=== \n");

    struct node *nextnode;
    int pos, i=1;
    temp = head;

    printf("Please enter position when you delete node: ");
    scanf("%d", &pos);

    while(i < pos-1) {
        temp = temp ->next;
        i++;
    }

    nextnode = temp ->next;
    temp ->next = nextnode ->next;
    free(nextnode);
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
