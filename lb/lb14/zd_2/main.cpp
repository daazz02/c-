#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    const int SIZE = 3;

    int** arr = new int*[SIZE];
    for (int i = 0; i < SIZE; ++i)
        arr[i] = new int[SIZE];

    int even = 0, odd = 0;

    std::cout << "Масив:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            arr[i][j] = rand() % 100;
            std::cout << arr[i][j] << "\t";
            if (arr[i][j] % 2 == 0) ++even;
            else ++odd;
        }
        std::cout << "\n";
    }

    std::cout << "Головна діагональ: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i][i] << " ";

    std::cout << "\nПобічна діагональ: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i][SIZE - 1 - i] << " ";

    std::cout << "\nПарних: " << even << "\nНепарних: " << odd << "\n";

    for (int i = 0; i < SIZE; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
