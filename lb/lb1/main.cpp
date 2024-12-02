#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, y;

    cout << "Введіть значення a: "; cin >> a;
    cout << "Введіть значення b: "; cin >> b;

    double numA = cbrt(a);
    double numB = cbrt(b);

    y = (0.81 * numA - (1 / 2.125) * numB) * exp(a);

    cout <<"Значення y: "<< y << endl;

    cout <<"and: ";

    return 0;
}
