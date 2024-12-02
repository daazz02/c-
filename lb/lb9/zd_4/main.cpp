#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int n = 10;
    int arr[n];
    int A;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Введіть число A: ";
    cin >> A;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > A) count++;
    }

    cout << "Кількість елементів більших за " << A << ": " << count << endl;

    return 0;
}
