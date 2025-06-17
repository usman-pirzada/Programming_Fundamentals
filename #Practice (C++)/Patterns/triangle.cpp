#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of triangle: ";
    cin >> n;
    
    cout << "\n";
    
    // 1st
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";
    // 2nd
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";

    // 3rd
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = 0; j < n-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    // 4th
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n-i; j++) {
            cout << " ";
        }

        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
