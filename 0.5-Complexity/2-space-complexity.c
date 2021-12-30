// Space Complexity of A Program

#include<stdio.h>

int main() {
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if(num%2 == 0) {
        printf("%d is even number.", num);
    } else {
        printf("%d is odd number.", num);
    }

    return 0;
}

/** Calculate Space complexity this program:
    Time complexity = O(1),
    Space complexity = O(1)
 */

