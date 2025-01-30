#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxPet=0, maxSupply=0;

void displayInventory(char ***petArray) {
	printf("\n\tYour Inventory:");
	for(int i=0; i < maxPet; i++) {
		printf("\nPET #%d\n", i+1);
		for(int j=0 ; j < maxSupply; j++) {
			printf("Supply #%d: %s\n", j+1, petArray[i][j]);
		}
	}
}

void removeSupply(char ***petArray) {
	displayInventory(petArray);
	int petNo;
	printf("\nEnter Pet number to delete it along with its supplies: ");
	scanf("%d", &petNo);
	for(int i=0 ; i<maxSupply; i++) {
		petArray[(petNo-1)][i][0] = '\0';
	}
	printf("\nPet removed Successfully!!");
}

//void addMoreSupply(char petArr[][maxSupply]) {
//	
//}


int main() {
	printf("Enter no. of Pets: ");
	scanf("%d", &maxPet);
	printf("Enter no. of Supplies for each Pet: ");
	scanf("%d", &maxSupply);
	
//	char (*petArray)[maxSupply][20];
//	petArray = (char (*)[maxSupply][20])calloc(maxPet, sizeof(*petArray));
	char ***petArray;
	for(int i=0 ; i < maxPet; i++) {
		petArray[i] = (char**)calloc(maxSupply, sizeof(char*));
		for(int j=0; j<maxSupply; j++) {
			petArray[i][j] = (char*)calloc(25, sizeof(char));
		}
	}
	
	printf("\n\n\tStart Entering Supplies for the Pets:\n");
	for(int i=0; i < maxPet; i++) {
		printf("\nFOR PET #%d\n", i+1);
		for(int j=0 ; j < maxSupply; j++) {
			printf("Enter Supply #%d: ", j+1);
			scanf("%s", &petArray[i][j]);
		}
	}
	
	while(1){
		int option;
		printf("\nNow which operation do you want to perform: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				removeSupply(petArray);
				break;
			case 2:
				displayInventory(petArray);
				break;
			case 3:
				for(int i=0; i<maxPet; i++) {
					free(petArray[i]);
				}
				free(petArray);
				return 0;
//			case 4:
//				addMoreSupply();
//				break;
			default:
				printf("\nInvalid Input!!");
		}
	}
	
	for(int i=0; i<maxPet; i++) {
		free(petArray[i]);
	}
	free(petArray);
	
	return 0;
}