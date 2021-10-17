#include <iostream>

using namespace std;

class Time {
   private:
    int hours, minutes, seconds;

    void adjust() {
        minutes += (seconds / 60);
        seconds %= 60;

        hours += (minutes / 60);
        minutes %= 60;

        hours %= 24;
    }

   public:
    Time() : hours(0), minutes(0), seconds(0) {
    }

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        adjust();
    }

    Time(int h, int m, int s, char p) : minutes(0), seconds(0) {
        if (p == 'p') {
            hours = 12 + h;
        } else {
            hours = h;
        }
        adjust();
    }

    void show() {
        if (hours < 10) {
            cout << "0" << hours << ":";
        } else {
            cout << hours << ":";
        }
        if (minutes < 10) {
            cout << "0" << minutes << ":";
        } else {
            cout << minutes << ":";
        }
        if (seconds < 10) {
            cout << "0" << seconds << endl;
        } else {
            cout << seconds << endl;
        }
    }

    void add(Time time) {
        hours += time.hours;
        minutes += time.minutes;
        seconds += time.seconds;
        adjust();
    }

    Time operator+(Time& t) {
        Time temp;
        temp.hours = hours + t.hours;
        temp.minutes = minutes + t.minutes;
        temp.seconds = seconds + t.seconds;
        temp.adjust();
        return temp;
    };
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hh, mm, ss;
    cin >> hh >> mm >> ss;
    Time t1(hh, mm, ss);  //t1(hh, mm, ss)
    cin >> hh >> mm >> ss;
    Time t2(hh, mm, ss);
    Time t3;
    t3 = t1 + t2;  //adding two times should produce a valid time, overflowed hours/minutes/seconds should be adjusted.
    // e.g. adding 18:10:20 with 10:20:30 results in 4:30:50

    t1.show();
    t2.show();
    t3.show();
    return 0;
}