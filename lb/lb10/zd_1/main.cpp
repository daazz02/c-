#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    const int m = 4, n = 3;
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

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 == 0) {
                count++;
            }
        }
        cout << "Рядок " << i + 1 << ": " << count << " парних чисел." << endl;
    }

    return 0;
}
