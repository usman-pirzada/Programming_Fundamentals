#include <iostream>
using namespace std;

int main() {
    int num;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> num;

    for(int i=2; i*i <= num; i++) { // Only check divisibility up to the square root of "num" | or you can use i <= sqrt(num), but include cmath library
        if(num%i == 0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime) {
        cout << "The entered number is a Prime number!";
    } else {
        cout << "The entered number is not a Prime number!";
    }
    
    return 0;
}
