#include <stdio.h>
int main() { int i,j;
int arr1[] = {1, 2, 3};
int arr2[] = {4, 5, 6};
int arr3[] = {7, 8, 9};
int *ptrArr[] = {arr1,arr2,arr3};
printf("Original Array: \n");
for ( i = 0; i < 3; ++i) {
for ( j = 0; j < 3; ++j)
printf("%d ", ptrArr[i][j]);
printf("\n");
}//end for i
for ( i = 0; i < 3; ++i) {
int *start = ptrArr[i]; // Pointer to the first element
int *end = ptrArr[i] + 2; // Pointer to the last element
while (start < end) {
    // Display addresses and values before swap
printf("Before swap: start (%p) = %d, end (%p) = %d\n", start, *start, end, *end);
    
    // Swap the values
int temp = *start;
*start = *end;
*end = temp;
    
    // Move pointers
++start;
--end;
    
    // Display addresses and values after swap
printf("After swap: start (%p) = %d, end (%p) = %d\n", start, *start, end, *end);
}
}//end for i
printf("Modified: \n");
for ( i = 0; i < 3; ++i) {
for ( j = 0; j < 3; ++j)
printf("%d ", ptrArr[i][j]);
printf("\n");
}//end for i
return 0;
}//end main