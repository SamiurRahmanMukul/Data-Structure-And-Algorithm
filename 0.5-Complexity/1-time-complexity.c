// Time Complexity Of A Program

#include<stdio.h>

int main() {
    int n, count = 0;
    int x, y, z;

    printf("Enter value of `n`: ");
    scanf("%d", &n);

    // below nested for loop `Time complexity = O(n*n)`
    for(x=1; x<n; x++) {
        for(y=1; y<n; y++) {
            count = count + 1;
        }
    }

    // below for loop `Time complexity = O(n)`
    for(z=1; x<n; z++) {
        count = count + 1;
    }

    printf("Count = %d", count++);
    return 0;
}

/** Calculate Total Time complexity Of This Program:
    Here, This program total `Time complexity: O(n*n) + O(n) = O(n*n*n)`. But `Time complexity: O(n*n)` because a program `Big complexity` this program complexity. So that this program `Time complexity: O(n*n)`.
 */
