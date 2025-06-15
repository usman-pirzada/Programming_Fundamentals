#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_SUPPLY_CAPACITY 5
#define MAX_SPECIES 3
// Define string as a typedef for char *
typedef char* string;
const char* columnsname[] = {
	"**Animals**",
	"***Supplies***",
};
const char* columnsName[] = {
	"Dog",
	"Cat",
	"Parrot"
};
int numSpecies = 3; // Number of species
int* numSupplies; // Array to track the number of supplies for each species
string** speciesSupplies; // 2D dynamic array to store species supplies
// Initialize inventory
void initializeInventory() {
	numSupplies = (int*)malloc(numSpecies * sizeof(int)); // Allocate memory for supply counts
	speciesSupplies = (string**)malloc(numSpecies * sizeof(string*)); // Allocate memory for the rows (species)
	for (int i = 0; i < numSpecies; i++) {
		numSupplies[i] = 0; // Initially no supplies for any species
		speciesSupplies[i] = (string*)malloc(INITIAL_SUPPLY_CAPACITY * sizeof(string)); // Allocate memory for supplies for each species
	}
}
// Add a supply to a species
void addSupply(int speciesIndex, const char* supply) {
	speciesSupplies[speciesIndex][numSupplies[speciesIndex]] = (string)malloc(strlen(supply) + 1);
	strcpy(speciesSupplies[speciesIndex][numSupplies[speciesIndex]], supply);
	numSupplies[speciesIndex]++; // Increment the number of supplies for the species
}
// Update a supply for a species
void updateSupply(int speciesIndex, int supplyIndex, const char* newSupply) {
	if (supplyIndex < 0 || supplyIndex >= numSupplies[speciesIndex]) {
		printf("Invalid supply index.\n");
		return;
	}
// Free the old supply and allocate memory for the new one
	free(speciesSupplies[speciesIndex][supplyIndex]);
	speciesSupplies[speciesIndex][supplyIndex] = (string)malloc(strlen(newSupply) + 1);
	strcpy(speciesSupplies[speciesIndex][supplyIndex], newSupply);
}
// Remove a species from the inventory
void removeSpecies(int speciesIndex) {
// Free the supplies of the species
	for (int i = 0; i < numSupplies[speciesIndex]; i++) {
		free(speciesSupplies[speciesIndex][i]);
	}
	free(speciesSupplies[speciesIndex]); // Free the species' supply list
// Shift other species' supplies to fill the gap
	for (int i = speciesIndex; i < numSpecies - 1; i++) {
		speciesSupplies[i] = speciesSupplies[i + 1];
		numSupplies[i] = numSupplies[i + 1];
	}
// Reduce the number of species
	numSpecies--;
}
// Display inventory in 2D format
void displayInventory() {
	printf("\nInventory:\n");
// Print the header with species names
	for (int i = 0; i < 2; i++) {
	printf("%-30s", columnsname[i]);
	}
	printf("\n\n");
// Print supplies for each species
	for (int i = 0; i < numSpecies; i++) {
		printf("%-15s", columnsName[i]); // Print species name once per row
		for (int j = 0; j < numSupplies[i]; j++) {
//			if (j == 0) {
//			printf("%-15s", columnsName[i]); // Print species name once per row
//			}
			printf("%-15s", speciesSupplies[i][j]); // Print each supply
		}
		printf("\n");
	}
}
// Free allocated memory
void freeInventory() {
	for (int i = 0; i < numSpecies; i++) {
		for (int j = 0; j < numSupplies[i]; j++) {
			free(speciesSupplies[i][j]); // Free each supply
		}
		free(speciesSupplies[i]); // Free the species' supply list
	}
	free(speciesSupplies); // Free the 2D array of species supplies
	free(numSupplies); // Free the array tracking the number of supplies
}

int main() {
// Initialize the inventory
	initializeInventory();
// Adding supplies for "Dogs"
	addSupply(0, "Food");
	addSupply(0, "Leash");
	addSupply(0, "Toys");
	// Adding supplies for "Cats"
	addSupply(1, "Food");
	addSupply(1, "Litter");
	// Adding supplies for "Parrots"
	addSupply(2, "Seed");
	addSupply(2, "Cage");
	// Displaying inventory before updating
	printf("Before updating:\n");
	displayInventory();
	// Updating a supply for "Dogs" (Leash -> Collar)
	updateSupply(0, 1, "Collar");
	// Displaying inventory after update
	printf("\nAfter updating:\n");
	displayInventory();
	// Removing "Cats" species
	removeSpecies(1);
	// Displaying inventory after removal
	printf("\nAfter removing Cats:\n");
	displayInventory();
	// Free allocated memory
	freeInventory();
	return 0;
}