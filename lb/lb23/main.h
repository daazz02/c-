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

    Fraction plus(const Fraction& that) const;
    Fraction minus(const Fraction& that) const;
    Fraction times(const Fraction& that) const;
    Fraction by(const Fraction& that) const;

private:
    int numerator;
    int denominator;

    void reduce();
    int gcd(int a, int b);
};

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero");
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

Fraction Fraction::plus(const Fraction& that) const {
    int num = numerator * that.denominator + that.numerator * denominator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::minus(const Fraction& that) const {
    int num = numerator * that.denominator - that.numerator * denominator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::times(const Fraction& that) const {
    int num = numerator * that.numerator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::by(const Fraction& that) const {
    if (that.numerator == 0)
        throw invalid_argument("Division by zero");
    int num = numerator * that.denominator;
    int den = denominator * that.numerator;
    return Fraction(num, den);
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

        cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
        cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
        cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
        cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}



//3 / 4
//1 / 3

/*
3/4 + 1/3 = 1 1/12
3/4 - 1/3 = 5/12
3/4 * 1/3 = 1/4
3/4 / 1/3 = 2 1/4
*/