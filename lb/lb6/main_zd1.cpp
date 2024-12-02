#include <iostream>
using namespace std;

int main() {
    int N;
    long long product = 1;

    cout << "Введите натуральное число N: ";
    cin >> N;

    while (N > 0) {
        int digit = N % 10;
        if (digit != 7) {
            product *= digit;
        }
        N /= 10;
    }

    cout << "Произведение всех цифр, которые не равны 7: " << product << endl;

    return 0;
}
