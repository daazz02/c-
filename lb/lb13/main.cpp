#include <iostream>
#include <ctime>
#include <cstdlib>

const int SIZE = 5;

int main() {
    srand(time(0));
    int arr[SIZE][SIZE];

    int* ptr = &arr[0][0];
    std::cout << "Масив:\n";
    for (int i = 0; i < SIZE * SIZE; ++i) {
        *(ptr + i) = rand() % 100;
        std::cout << *(ptr + i) << "\t";
        if ((i + 1) % SIZE == 0) std::cout << "\n";
    }

    std::cout << "\nГоловна діагональ: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << *(*(arr + i) + i) << " ";

    std::cout << "\nПобічна діагональ: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << *(*(arr + i) + (SIZE - 1 - i)) << " ";

    int even = 0, odd = 0;
    ptr = &arr[0][0];
    for (int i = 0; i < SIZE * SIZE; ++i) {
        if (*(ptr + i) % 2 == 0)
            ++even;
        else
            ++odd;
    }

    std::cout << "\nКількість парних елементів: " << even;
    std::cout << "\nКількість непарних елементів: " << odd << "\n";

    return 0;
}
