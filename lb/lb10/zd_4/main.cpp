#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    const int m = 4, n = 6;
    int arr[m][n];

    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100 - 50;
        }
    }

    cout << "Матриця:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += arr[i][j];
        }
        cout << "Стовпчик " << j + 1 << ": сума = " << sum << endl;
    }

    return 0;
}
