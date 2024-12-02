#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int m = 10;
    int arr[m] = {-3, -5, 7, -1, 2, 15, -4, 9, -6, 11};


    cout << "Початковий масив: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    int max_value = *max_element(arr, arr + m);
    int max_index = distance(arr, find(arr, arr + m, max_value));


    for (int i = 0; i < max_index; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
    }


    cout << "Змінений масив: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
