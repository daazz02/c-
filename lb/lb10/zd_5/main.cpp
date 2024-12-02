#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    const int m = 3, n = 4;
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

    int maxVal = arr[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "Максимальний елемент: " << maxVal << " на позиції (" << maxRow + 1 << ", " << maxCol + 1 << ")." << endl;

    return 0;
}
