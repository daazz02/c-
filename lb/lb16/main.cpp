#include <iostream>
#include <ctime>
using namespace std;

struct Date {
    int year, month, day;
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeap(year)) return 29;
    return daysInMonth[month - 1];
}

Date today(void) {
    time_t t = time(NULL);
    tm* tl = localtime(&t);
    return {tl->tm_year + 1900, tl->tm_mon + 1, tl->tm_mday};
}

int daysBetween(Date from, Date to) {
    int days = 0;
    while (from.year < to.year || from.month < to.month || from.day < to.day) {
        days++;
        from.day++;
        if (from.day > monthLength(from.year, from.month)) {
            from.day = 1;
            from.month++;
            if (from.month > 12) {
                from.month = 1;
                from.year++;
            }
        }
    }
    return days;
}

int main() {
    Date birth = {2006, 04, 28};
    Date now = today();
    cout << "Сьогодні: " << now.year << "-" << now.month << "-" << now.day << endl;
    cout << "Днів від народження: " << daysBetween(birth, now) << endl;
    return 0;
}
