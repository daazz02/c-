#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int m = 12;
    int arr[m] = {5, 12, 7, 3, 8, 10, 2, 6, 4, 11, 9, 1};

    cout << "Початковий масив: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + m);
    cout << "Упорядкування за зростанням: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + m, greater<int>());
    cout << "Упорядкування за спаданням: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
