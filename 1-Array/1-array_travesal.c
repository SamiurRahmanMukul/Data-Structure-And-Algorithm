#include<stdio.h>

int main() {
    int a[5];
    int i;

    // getting user input of array
    for (i=0; i<5; i++) {
        printf("Please enter element of a[%d] = ", i+1);
        scanf("%d", &a[i]);
    }

    // now traverse array for printing array elements
    for (i=0; i<5; i++) {
        printf("\n\t a[%d] = %d", i+1, a[i]);
    }
    printf("\n");

    return 0;
    getch();
}
