/**
    </> single LinkedList insertion </>
        1. insert at beginning
        2. insert at end
        3. inset at user define position
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp;

// function prototype call
void insetAtStart();
void insertAtEnd();
void insertAtSpecific();
void traverseElements();

int main()
{
    int pos;

    printf("When you are insert elements at linkedList? \n\t insetAtStart to enter: 1 \n\t insertAtEnd to enter: 2 \n\t insertAtSpecific to enter: 3 \n\t noElementInsert to exit: 0 \n\t Please enter you decision: ");
    scanf("%d", &pos);

    switch(pos)
    {
    case 1:
    {
        insetAtStart();
        traverseElements();
        break;
    }
    case 2:
    {
        insertAtEnd();
        traverseElements();
        break;
    }
    case 3:
    {
        insertAtSpecific();
        traverseElements();
        break;
    }
    case 0:
    {
        printf("\n\t Ohh! You are successfully exit. \n");
        break;
    }
    default:
    {
        printf("\n\t Ohh! You are wrong response. Try to again thanks \n");
    }
    }

    return 0;
    getch();
}

/// create a insertAtStart() function to insert elements at beginning on linkedList
void insetAtStart()
{
    int chose;

    while(chose)
    {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("\n\t Please enter element: ");
        scanf("%d", &newnode -> data);
        newnode -> next = head;
        head = newnode;

        printf("\n Do you continue add elements to linkedList? \n\t(if exit enter: 0 / Enter: 1): ");
        scanf("%d", &chose);
        if (chose == 0)
        {
            break;
        }
    }
}

/// create a insertAtEnd() function to insert elements at end on linkedList
void insertAtEnd()
{
    int chose;

    while(chose)
    {
        struct node *head, *newnode, *temp;
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("\n\t Please enter element: ");
        scanf("%d", &newnode -> data);
        newnode -> next = 0;
        temp = head;

        while(temp -> next != 0)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;

        printf("\n Do you continue add elements to linkedList? \n\t(if exit enter: 0 / Enter: 1): ");
        scanf("%d", &chose);
        if (chose == 0)
        {
            break;
        }
    }
}

/// create a insertAtSpecific() function to insert elements at user define on linkedList
void insertAtSpecific()
{
    int chose;

    while(chose)
    {
        struct node *head, *newnode, *temp;

        int pos, count=1, i=1;

        newnode = (struct node*)malloc(sizeof(struct node));

        printf("\n\t Enter position when you insert element: ");
        scanf("%d", &pos);

        if (pos > count)
        {
            printf("\n\t Opps! Invalid position. Try again thanks");
        }
        else
        {
            temp = head;
            while(i < pos)
            {
                temp = temp -> next;
                i++;
            }

            printf("\n\t Please enter element: ");
            scanf("%d", &newnode -> data);
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }

        printf("\n Do you continue add elements to linkedList? \n\t(if exit enter: 0 / Enter: 1): ");
        scanf("%d", &chose);
        if (chose == 0)
        {
            break;
        }
    }
}

/// traverse / print elements of linkedList
void traverseElements()
{
    int count=0;

    // traverse / print elements of linkedList
    temp = head;
    while (temp !=0)
    {
        printf("\n\t Linked elements of [%d] = %d", count+1, temp -> data);
        temp = temp -> next;
        count ++;
    }
    printf("\n");
}
