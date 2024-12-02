#include <iostream>

using namespace std;

int main() {
    double x, y;

    cout << "Введіть координати точки (x y): ";
    cin >> x >> y;


    if ((x >= -1 && x <= 0 && y >= 0 && y <= 1) ||
        (x >= 0 && x <= 1 && y >= -1 && y <= 0)) {
        cout << "Точка належить заштрихованій області." << endl;
        } else {
            cout << "Точка не належить заштрихованій області." << endl;
        }

    return 0;
}























// #include <iostream>
// #include <cmath>
//
// using namespace std;
//
// int main() {
//     double x, y;
//
//     cout << "Введіть значення x: ";
//     cin >> x;
//
//     if (x <= 1) {
//         y = 0.5 * cos(x) + 4 * x;
//     } else if (x < 0) {
//         y = 0.25 * pow(x, 4) + 2 * pow(x, 2);
//     } else if (x > 1) {
//         y = 0.9 * sqrt(x) - 0.8 * x;
//     }
//
//     cout << "Y = " << y << endl;
//
//     return 0;
// }