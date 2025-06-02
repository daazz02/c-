#include <iostream>
using namespace std;

class LazySquare {
private:
    double side;
    double area;
    bool side_changed;

public:
    LazySquare(double s) {
        side = s;
        area = s * s;
        side_changed = false;
    }

    void set_side(double s) {
        if (s >= 0 && s != side) {
            side = s;
            side_changed = true;
        }
    }

    double get_area() {
        if (side_changed) {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

    bool changet() {
        return side_changed;
    }
};

int main() {
    LazySquare square(5);
    cout << "Area: " << square.get_area() << endl;
    square.set_side(10);
    cout << "Changed: " << (square.changet() ? "Yes" : "No") << endl;
    cout << "Area: " << square.get_area() << endl;
    cout << "Changed: " << (square.changet() ? "Yes" : "No") << endl;
    return 0;
}
