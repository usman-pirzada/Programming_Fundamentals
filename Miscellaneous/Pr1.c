#include <stdio.h>
const int rows = 5;
const int cols = 6;

void addStudent(int seatNo, char *allSeats[][cols]) {
	char name[20];
	int row = (seatNo-1) / cols;
	int col = (seatNo-1) % cols;
	
	printf("enter student name: ");
	scanf("%s", &name);
	allSeats[row][col] = name;
}

void removeStudent(int seatNo, char *allSeats[][cols]) {
	int row = (seatNo-1) / cols;
	int col = (seatNo-1) % cols;
	
	allSeats[row][cols] = "0";
}

void displaySeatArr(char *allSeats[][cols]) {
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("%s\t", allSeats[i][j]);
		}
		printf("\n");
	}
}

int main() {
	char *allSeats[rows][cols];
	int seatNo;
	// initiate matrix
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			allSeats[i][j] = "0";
		}
	}
	
while(1) {
	int option;
	printf("Please an option: ");
	scanf("%d", &option);
	switch(option) {
		case 1:
			displaySeatArr(allSeats);
			break;
		case 2:
			printf("\nenter seat no: ");
			scanf("%d", &seatNo);
			addStudent(seatNo, allSeats);
			break;
		case 3:
			printf("\nenter seat no: ");
			scanf("%d", &seatNo);
			removeStudent(seatNo, allSeats);
			break;
		case 4:
			return 0;
		default:
			printf("\nInvalid selection!");
	}
}
}
