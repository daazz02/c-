#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);

    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;

    // Метод для сокращения дроби
    void reduce();
    int gcd(int a, int b);
};

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }

    // Приводим знак к числителю
    if (den < 0) {
        num = -num;
        den = -den;
    }

    numerator = num;
    denominator = den;
    reduce();
}

int Fraction::gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

string Fraction::toString() {
    int whole = numerator / denominator;
    int remainder = abs(numerator % denominator);

    ostringstream oss;

    if (remainder == 0) {
        oss << whole;
    } else if (whole == 0) {
        if (numerator < 0)
            oss << "-";
        oss << remainder << "/" << denominator;
    } else {
        oss << whole << " " << remainder << "/" << denominator;
    }

    return oss.str();
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    string input;
    cout << "Enter a fraction (e.g. 3 / 4): ";
    getline(cin, input);

    int num, den;
    char slash;

    istringstream iss(input);
    if (!(iss >> num >> slash >> den) || slash != '/') {
        cout << "Invalid input format." << endl;
        return 1;
    }

    try {
        Fraction fraction(num, den);
        cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
