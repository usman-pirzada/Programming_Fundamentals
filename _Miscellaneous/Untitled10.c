#include <stdio.h>

int calc(int (*arr)[7], int rowNo, int colNo) {
	if(colNo >= 7) {
		return 0;
	}
	
	return (arr[rowNo][colNo] + calc(arr, rowNo, colNo+1));
}

int main() {
	int arr[7][7], weekly = 0;
	
	for(int i=0; i<7; i++) {
		for(int j=0; j<7; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(int i=0; i<7; i++) {
		printf("\n\n\tFor District#%d", i+1);
		for(int j=0; j<7; j++) {
			weekly = calc(arr, i, 0);
		}
		printf("\nTotal weekly rainfall is: %d", weekly);
	}
	
	return 0;
}
