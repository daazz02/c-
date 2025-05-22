#include <iostream>
using namespace std;

int main(void) {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);

    int* p = vector;
    int* end = vector + n;
    int min = *p;

    for (; p < end; p++) {
        if (*p < min) {
            min = *p;
        }
    }

    cout << "Найменший елемент масиву: " << min << endl;
    return 0;
}
