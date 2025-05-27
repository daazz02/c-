#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int n = 10;
    float* arr = new float[n];

    int positive = 0, negative = 0;
    for (int i = 0; i < n; ++i) {
        arr[i] = ((float)rand() / RAND_MAX) * 4.0f - 2.0f;
        std::cout << arr[i] << " ";
        if (arr[i] > 0) ++positive;
        else if (arr[i] < 0) ++negative;
    }

    std::cout << "\nДодатні: " << positive;
    std::cout << "\nВід’ємні: " << negative << "\n";

    delete[] arr;
    return 0;
}
