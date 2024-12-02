#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    const int m = 4, n = 7;
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

    int minVal = arr[0][0];
    int minRow = 0, minCol = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    cout << "Мінімальний елемент: " << minVal << " на позиції ("
         << minRow + 1 << ", " << minCol + 1 << ")." << endl;

    return 0;
}
