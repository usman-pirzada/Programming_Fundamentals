#include <stdio.h>

#define ROWS 5
#define COLS 6

// Function to print the current seating chart
void printSeating(char seating[ROWS][COLS]) {
    printf("\nCurrent Seating Arrangement:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seating[i][j] == 'X') {
                printf("  [ X ] ");
            } else {
                printf("  [ 0 ] "); // 0 for empty seats
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add a student to an available seat
void addStudent(char seating[ROWS][COLS], int seatNumber) {
    if (seatNumber < 1 || seatNumber > ROWS * COLS) {
        printf("Invalid seat number. Please enter a number between 1 and %d.\n", ROWS * COLS);
        return;
    }

    int row = (seatNumber - 1) / COLS;
    int col = (seatNumber - 1) % COLS;

    if (seating[row][col] == 'X') {
        printf("Seat number %d is already occupied.\n", seatNumber);
    } else {
        seating[row][col] = 'X';  // Mark the seat as occupied
        printf("Student added to seat %d.\n", seatNumber);
    }
}

// Function to remove a student from a seat
void removeStudent(char seating[ROWS][COLS], int seatNumber) {
    if (seatNumber < 1 || seatNumber > ROWS * COLS) {
        printf("Invalid seat number. Please enter a number between 1 and %d.\n", ROWS * COLS);
        return;
    }

    int row = (seatNumber - 1) / COLS;
    int col = (seatNumber - 1) % COLS;

    if (seating[row][col] == 'X') {
        seating[row][col] = 0;  // Mark the seat as empty
        printf("Student removed from seat %d.\n", seatNumber);
    } else {
        printf("Seat number %d is already empty.\n", seatNumber);
    }
}

int main() {
    char seating[ROWS][COLS] = {0};
    int choice, seatNumber;

    do {
        printf("Seating Chart Management System\n");
        printf("1. View Seating Chart\n");
        printf("2. Add Student to Seat\n");
        printf("3. Remove Student from Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printSeating(seating);
                break;
            case 2:
                printf("Enter the seat number to assign to a student (1-%d): ", ROWS * COLS);
                scanf("%d", &seatNumber);
                addStudent(seating, seatNumber);
                break;
            case 3:
                printf("Enter the seat number to remove the student from (1-%d): ", ROWS * COLS);
                scanf("%d", &seatNumber);
                removeStudent(seating, seatNumber);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}