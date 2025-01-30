#include <stdio.h>

typedef struct {
    int arr[5];
} Array1D;

// Function that modifies the array inside the structure
void modify1DArray(Array1D array) {
    for (int i = 0; i < 5; i++) {
        array.arr[i] += 10; // Increment each element by 10
    }
    printf("Inside Function: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array.arr[i]);
    }
    printf("\n");
}

int main() {
    Array1D array = {{1, 2, 3, 4, 5}};

    modify1DArray(array);

    printf("Outside Function: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array.arr[i]); // Original array remains unchanged
    }
    printf("\n");
    return 0;
}