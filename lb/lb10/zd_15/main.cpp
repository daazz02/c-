#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    const int m = 3, n = 3;
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

    int mainDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < m; i++) {
        mainDiagonalSum += arr[i][i];
        secondaryDiagonalSum += arr[i][n -
