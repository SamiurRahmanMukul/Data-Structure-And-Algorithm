/**
    </> Implementation of single LinkedList </>
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp;

    head=0;
    int chose, count=0; /// here 'count' size of linkedList

    while(chose)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter elements of linkedList: ");
        scanf("%d", &newnode -> data);
        newnode -> next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }

        printf("\nDo you continue add elements to linkedList? \n\t(if exit enter: 0 / Enter: 1): ");
        scanf("%d", &chose);
        if (chose == 0)
        {
            break;
        }
    }

    // traverse / print elements of linkedList
    temp = head;
    while (temp !=0)
    {
        printf("\n\t Linked elements of [%d] = %d", count+1, temp -> data);
        temp = temp -> next;
        count ++;
    }
    printf("\n");

    return 0;
    getch();
}
