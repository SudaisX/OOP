#include <iostream>
using namespace std;

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;

    void show() {
        cout << day << ":" << month << ":" << year << endl;
    }

    bool isEqual(Date date) {
        if (date.day == day && date.month == month && date.year == year) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Date date1, date2;

    cin >> date1.day;
    cin >> date1.month;
    cin >> date1.year;
    cout << "Date 1 : ";
    date1.show();

    cin >> date2.day;
    cin >> date2.month;
    cin >> date2.year;
    cout << "Date 2 : ";
    date2.show();

    if (date1.isEqual(date2)) {
        cout << "Dates are equal";
    } else {
        cout << "Dates are not equal";
    }

    return 0;
}