/**
    Example array insertion:
        6   2   0   5   3
                8   0   5   3   -> array insert data specific position
*/

#include<stdio.h>

int main()
{
    int arr[50];
    int siz, num, pos, i;

    printf("Please enter size of array : ");
    scanf("%d", &siz);

    // getting user input for this array
    for (i=0; i<siz; i++)
    {
        printf("Enter element of arr[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }

    // printing original array elements
    for (i=0; i<siz; i++)
    {
        printf("\n\t arr[%d] = %d", i+1, arr[i]);
    }

    printf("\n\nPlease enter data you insert : ");
    scanf("%d", &num);

    printf("Please enter position when data you insert : ");
    scanf("%d", &pos);

    // check user input array position validation
    if (pos <= 0 || pos >= siz+1)
    {
        printf("\n\tInvalid Position!\n");
    }
    else
    {
        // empty set user define position
        for (i=siz-1; i>=pos-1; i--)
        {
            arr[i+1] = arr[i];
        }

        arr[pos-1] = num; // specific position data set
        siz++;

        // inserted array elements print
        for (i=0; i<siz; i++)
        {
            printf("\n\t arr[%d] = %d", i+1, arr[i]);
        }
        printf("\n");
    }

    return 0;
    getch();
}
