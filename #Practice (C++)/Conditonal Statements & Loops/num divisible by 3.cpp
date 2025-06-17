#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Numbers divisible by 3 upto " << n << ":" << endl;
    for (int i = 1; i <= n; i++) {
        if(i%3 == 0) {
            cout << i << endl;
        }
    }
    
    return 0;
}
