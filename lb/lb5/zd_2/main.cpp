#include <iostream>

int main() {
    long long product = 1;

    for (int i = 3; i <= 100; i += 3) {
        product *= i;
    }

    std::cout << "Произведение чисел, кратных 3 и не больших 100: " << product << "\n";

    return 0;
}