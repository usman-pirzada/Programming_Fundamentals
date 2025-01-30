#include <stdio.h>

void display(char* str) {
	printf("\n%s", str);
}

int main() {
	char str[10];
	scanf("%[^\n]s", str);
	display(str);
}                 