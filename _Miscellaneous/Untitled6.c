#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows = 2, cols = 3;

    printf("Elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*arr + i * cols + j)); // Access using pointer arithmetic
//            printf("%d ", arr[i][j]); // Access using pointer arithmetic
        }
        printf("\n");
    }
    return 0;
}