/**
    Example array deletion:
        6   2   0   5   3
        6   2   5   3       -> after array delete data specific position
*/

#include<stdio.h>

int main() {
    int arr[50];
    int siz, num, pos, i;

    printf("Please enter size of array : ");
    scanf("%d", &siz);

    // getting user for in this array
    for (i=0; i<siz; i++) {
        printf("Enter element of arr[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }

    // printing original array elements
    for (i=0; i<siz; i++) {
        printf("\n\t arr[%d] = %d", i+1, arr[i]);
    }

    // specific position delete now
    printf("\n\nPlease enter position when are you delete : ");
    scanf("%d", &pos);

    if (pos <= 0 || pos >= siz+1) {
        printf("\n\tInvalid Position!\n");
    } else {
        for (i=pos-1; i<siz-1; i++) {
            arr[i] = arr[i+1];
        }

        siz--;
    }

    // if delete first number element of array
    /* for (i=0; i<siz-1; i++)
    {
        arr[i] = arr[i+1];
    }
    siz--; */

    // now printing after delete array element
    for (i=0; i<siz; i++) {
        printf("\n\t arr[%d] = %d", i+1, arr[i]);
    }
    printf("\n");

    return 0;
    getch();
}
