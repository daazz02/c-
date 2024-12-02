#include <iostream>
using namespace std;

struct Date {
    int hours;
    int minutes;
};

int main() {
    Date startTime;
    int minutesPassed;

    cout << "Введіть години початкового часу: ";
    cin >> startTime.hours;
    cout << "Введіть хвилини початкового часу: ";
    cin >> startTime.minutes;

    cout << "Введіть кількість хвилин, які пройшли: ";
    cin >> minutesPassed;

    startTime.minutes += minutesPassed;

    startTime.hours += startTime.minutes / 60;
    startTime.minutes %= 60;

    startTime.hours %= 24;

    cout << "Час через " << minutesPassed << " хвилин: ";
    cout << startTime.hours << ":" << (startTime.minutes < 10 ? "0" : "") << startTime.minutes << endl;

    return 0;
}
