#include<stdio.h>

int main()
{
    int size, i;
    printf("Please enter size of array : ");
    scanf("%d", &size);

    // declare a dynamic array
    int list[size];

    // getting user input for array
    for (i=0; i<size; i++)
    {
        printf("Please enter element of list[%d] : ", i+1);
        scanf("%d", &list[i]);
    }

    // traverse array for printing array element
    for (i=0; i<size; i++)
    {
        printf("\n\t list[%d] = %d", i+1, list[i]);
    }
    printf("\n");

    // printing array element memory address
    for (i=0; i<size; i++)
    {
        printf("\n\t Address of list[%d] = %d", i+1, &list[i]);
    }
    printf("\n");

    return 0;
    getch();
}
