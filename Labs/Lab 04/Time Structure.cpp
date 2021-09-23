#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(Time t1) {
    long totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    return totalsecs;
}

Time secs_to_time(long seconds) {
    Time t;
    t.hours = seconds / 3600;
    t.minutes = (seconds % 3600) / 60;
    t.seconds = (seconds % 3600) % 60;
    return t;
}

int main() {
    string s;
    cin >> s;

    if (s == "time_to_secs") {
        Time t;
        cin >> t.hours;
        cin >> t.minutes;
        cin >> t.seconds;
        cout << time_to_secs(t) << endl;
    } else if (s == "secs_to_time") {
        long totalseconds;
        cin >> totalseconds;
        Time t = secs_to_time(totalseconds);
        cout << t.hours << " hours, " << t.minutes << " minutes and " << t.seconds << " seconds.";
    }

    return 0;
}