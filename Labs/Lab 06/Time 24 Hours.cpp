#include<iostream>
using namespace std;

class Time24 {
    private:
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        
        void adjust() {
            minutes += (seconds / 60);
            seconds %= 60;

            hours += (minutes / 60);
            minutes %= 60;
            
            hours %= 24;
        }
        
    public:
        Time24(int h, int m, int s) {\
            hours = h;
            minutes = m;
            seconds = s;
            adjust();
        }
        
        Time24(int h, int m, int s, char p) { 
            if (p == 'p') {
                hours = 12 + h;
            } else {
                hours = h;
            }
            minutes = m;
            seconds = s;
            adjust();
            
        }
        
        void show(){
            if(hours < 10){
                cout << "0" << hours << ":";
            } else {
                cout << hours << ":";
            }
            if(minutes < 10){
                cout << "0" << minutes << ":";
            } else {
                cout << minutes << ":";
            }
            if(seconds < 10){
                cout << "0" << seconds << endl;
            } else {
                cout << seconds << endl;
            }
        }
        
        void add(Time24 time){
            hours += time.hours;
            minutes += time.minutes;
            seconds += time.seconds;
            adjust();
        }
        
};

int main(){
    int hours1, minutes1, seconds1;
    cin>>hours1>>minutes1>>seconds1;
    Time24 t1(hours1, minutes1, seconds1);


    int hours2, minutes2, seconds2;
    char period;
    cin>>hours2>>minutes2>>seconds2>>period;
    Time24 t2 = {hours2, minutes2, seconds2, period};

    cout<<"t1: "; t1.show();
    cout<<"t2: "; t2.show();

    t1.add(t2);// result of addition is stored in t1
    cout<<"t1+t2: "; t1.show();
}