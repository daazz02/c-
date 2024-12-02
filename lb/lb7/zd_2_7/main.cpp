#include <iostream>
#include <iomanip> // For setting precision
using namespace std;

int main() {
    double pi4 = 0.0;
    long n;

    cout << "Number of iterations? ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of iterations must be greater than 0." << endl;
        return 1;
    }

    for (long i = 0; i < n; i++) {
        if (i % 2 == 0) {
            pi4 += 1.0 / (2 * i + 1);
        } else {
            pi4 -= 1.0 / (2 * i + 1);
        }
    }

    cout << fixed << setprecision(20);
    cout << "Pi = " << (pi4 * 4.0) << endl;

    return 0;
}
