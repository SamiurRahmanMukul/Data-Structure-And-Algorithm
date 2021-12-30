#include<stdio.h>

int main() {
    int a[2][3];
    int i, j;

    // getting user input for 2D array
    for (i=0; i<2; i++) {
        for (j=0; j<3; j++) {
            printf("Please enter element of a[%d][%d] : ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    // printing 2D array elements
    for (i=0; i<2; i++) {
        for (j=0; j<3; j++) {
            printf("\n\t a[%d][%d] = %d", i+1, j+1, a[i][j]);
        }
    }
    printf("\n");

    return 0;
    getch();
}
