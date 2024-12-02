#include <iostream>
#include <string>

int main() {
    int num1, num2, num3, num4;

    std::cout << "Введите четыре числа от 1 до 255:\n";
    std::cin >> num1 >> num2 >> num3 >> num4;

    if ((num1 < 1 || num1 > 255) ||
        (num2 < 1 || num2 > 255) ||
        (num3 < 1 || num3 > 255) ||
        (num4 < 1 || num4 > 255)) {
        std::cerr << "Ошибка: все числа должны быть в диапазоне от 1 до 255.\n";
        return 1;
        }

    std::cout << "IP адрес: " << num1 << "." << num2 << "." << num3 << "." << num4 << "\n";

    return 0;
}
