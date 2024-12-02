#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, h;

    std::cout << "Введите значения a, b и h:\n";
    std::cin >> a >> b >> h;

    std::cout << "-------------------\n";
    std::cout << ":    X   :     Y    :\n";
    std::cout << "-------------------\n";

    for (double x = a; x <= b; x += h) {
        double y = x - sin(x);
        std::cout << ": " << std::setw(6) << x << " : " << std::setw(8) << y << " :\n";
    }

    std::cout << "-------------------\n";

    return 0;
}
