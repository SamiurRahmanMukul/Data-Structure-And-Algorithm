#include <stdio.h>

int main() {
    // variable
    int numbers[] = {10, 20, 30, 40, 50};

    // calculate size in bytes
    int arraySize = sizeof(numbers);
    int intSize = sizeof(numbers[0]);

    // length
    int length = arraySize / intSize;

    printf("ArraySize = %d bytes.\n", arraySize);
    printf("IntSize = %d bytes.\n", intSize);
    printf("Length of array = %d \n", length);

    return 0;
}
