#include <iostream>
using namespace std;

int main() {
    
    char ch;

    cout << "Enter an alphabet: ";
    cin >> ch;

    if(ch >= 'a' && ch <= 'z') {
        cout << "\nYou have entered a lowercase ch!";
    } else if((ch >= 'A' && ch <= 'Z')) {
        cout << "\nYou have entered an uppercase ch!";
    } else {
        cout << "\nIncorrect alphabet entered!!";
    }
    
    return 0;
}
