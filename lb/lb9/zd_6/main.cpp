#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int n = 10;
    int arr[n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 21 - 10;
    }

    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cout << "Перший нульовий елемент знаходиться на індексі: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "У масиві немає нульових елементів." << endl;
    }

    return 0;
}
