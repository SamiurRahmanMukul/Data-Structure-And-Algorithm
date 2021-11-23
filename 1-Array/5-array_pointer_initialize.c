#include<stdio.h>

int main()
{
    int a[5];
    int *q=a;
    int i;

    for (i=0; i<5; i++)
    {
        printf("Enter elements of a[%d] : ", i+1);
        // scanf("%d", &a[i]);
        scanf("%d", &q[i]); /// if replace same output
    }

    // pointer array elements
    for (i=0; i<5; i++)
    {
        printf("\n\t a[%d] = %d", i+1, a[i]);
    }
    printf("\n");

    return 0;
    getch();
}
