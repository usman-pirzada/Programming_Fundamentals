#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
	
    printf("The GCD of %d and %d is: %d\n", a, b, gcd(a, b));

    return 0;
}