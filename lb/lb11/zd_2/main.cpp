#include <iostream>
using namespace std;


struct Date {
    int hours;
    int minutes;
};

int main() {
    Date startTime, endTime;

    cout << "Введіть час початку події (години хвилини): ";
    cin >> startTime.hours >> startTime.minutes;

    cout << "Введіть час завершення події (години хвилини): ";
    cin >> endTime.hours >> endTime.minutes;

    int startTotalMinutes = startTime.hours * 60 + startTime.minutes;
    int endTotalMinutes = endTime.hours * 60 + endTime.minutes;

    if (endTotalMinutes < startTotalMinutes) {
        endTotalMinutes += 24 * 60;
    }

    int durationMinutes = endTotalMinutes - startTotalMinutes;

    int durationHours = durationMinutes / 60;
    durationMinutes %= 60;

    cout << "Тривалість події: " << durationHours << ":" << (durationMinutes < 10 ? "0" : "") << durationMinutes << endl;

    return 0;
}
