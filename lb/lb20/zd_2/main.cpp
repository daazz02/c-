#include <iostream>
using namespace std;

class Square {
private:
    double side;
    double area;

public:
    Square(double s) {
        set_side(s);
    }

    void set_side(double s) {
        if (s >= 0) {
            side = s;
            area = s * s;
        }
    }

    void print() {
        cout << "Square: side=" << side << " area=" << area << endl;
    }
};

int main() {
    Square s(4);
    s.print();

    s.set_side(2.0);
    s.print();

    s.set_side(-33.0);
    s.print();

    return 0;
}
