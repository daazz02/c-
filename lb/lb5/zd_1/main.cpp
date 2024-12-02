#include <iostream>
#include <cmath>

int main() {
    double x, y;

    std::cout << "Введите пять значений x:\n";
    for (int i = 0; i < 5; ++i) {
        std::cin >> x;
        y = 5 - 15 * sin(x) + x * x;
        std::cout << "При x = " << x << ", y = " << y << "\n";
    }

    return 0;
}
