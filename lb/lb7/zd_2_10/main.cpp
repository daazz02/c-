#include <iostream>
using namespace std;

int main() {
    int n;
    const int MAX_SIZE = 20;

    cout << "Enter the side size of the square (greater than 1): ";
    cin >> n;

    if (n <= 1) {
        cout << "The size must be greater than 1." << endl;
        return 1;
    } else if (n > MAX_SIZE) {
        cout << "Sorry, the side size is too big." << endl;
        return 1;
    }

    // Top border
    cout << '+';
    for (int i = 0; i < n; i++) cout << '-';
    cout << '+' << endl;

    // Middle rows
    for (int i = 0; i < n; i++) {
        cout << '|';
        for (int j = 0; j < n; j++) cout << ' ';
        cout << '|' << endl;
    }

    // Bottom border
    cout << '+';
    for (int i = 0; i < n; i++) cout << '-';
    cout << '+' << endl;

    return 0;
}
