#include <iostream>
using namespace std;

const int DivideByZero = 111;

float div(float arg1, float arg2) {
    if (arg2 == 0.0) {
        throw DivideByZero;
    }
    return arg1 / arg2;
}

int main() {
    float a, b, r;

    while (cin >> a >> b) {
        try {
            r = div(a, b);
            cout << r << endl;
        } catch (int ex) {
            if (ex == DivideByZero) {
                cout << "Are you kidding me?" << endl;
                cout << "Your input is not valid. You can't divide by zero." << endl;
            }
        }
    }

    return 0;
}
