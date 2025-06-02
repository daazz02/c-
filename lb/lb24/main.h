#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1);

    string toString() const;
    double toDouble() const;

    bool isGreaterThan(const Fraction& that) const;
    bool isLessThan(const Fraction& that) const;
    bool isEqual(const Fraction& that) const;

private:
    int numerator;
    int denominator;

    void reduce();
    int gcd(int a, int b);
};

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }

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

string Fraction::toString() const {
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

double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

bool Fraction::isGreaterThan(const Fraction& that) const {
    return this->numerator * that.denominator > that.numerator * this->denominator;
}

bool Fraction::isLessThan(const Fraction& that) const {
    return this->numerator * that.denominator < that.numerator * this->denominator;
}

bool Fraction::isEqual(const Fraction& that) const {
    return this->numerator * that.denominator == that.numerator * this->denominator;
}

int main() {
    string input1, input2;
    int num1, den1, num2, den2;
    char slash;

    cout << "Enter first fraction (e.g. 3 / 4): ";
    getline(cin, input1);
    istringstream iss1(input1);
    iss1 >> num1 >> slash >> den1;

    cout << "Enter second fraction (e.g. 1 / 3): ";
    getline(cin, input2);
    istringstream iss2(input2);
    iss2 >> num2 >> slash >> den2;

    try {
        Fraction f1(num1, den1);
        Fraction f2(num2, den2);

        if (f1.isGreaterThan(f2)) {
            cout << f1.toString() << " > " << f2.toString() << endl;
        } else if (f1.isLessThan(f2)) {
            cout << f1.toString() << " < " << f2.toString() << endl;
        } else {
            cout << f1.toString() << " = " << f2.toString() << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}



/*
 7 / 4
-6 / 10

1 3/4 > -3/5
*/
