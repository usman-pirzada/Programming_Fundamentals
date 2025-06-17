#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number for the length of square: ";
    cin >> n;

    // With integers (reset count at each new line)
    for (int i=0; i<n; i++) {
        for (int j = 1; j<=n; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    // With integers (continue count at each new line)
    int num = 1;
    for (int i=0; i<n; i++) {
        for (int j = 1; j<=n; j++) {
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }

    cout << endl;

    // With alphabets
    for (int i=0; i<n; i++) {
        for (int j = 65; j<(65+n); j++) {
            cout << (char) j << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}
