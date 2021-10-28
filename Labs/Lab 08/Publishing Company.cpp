#include <iostream>
using namespace std;

class publication {
    public:
        string title;
        float price;
        
        void getdata() {
            getline(cin, title);
            cin >> price;
        }
        
        void putdata() {
            cout << "Publication title: " << title << endl;
            cout << "Publication price: " << price << endl;
        }
        
};

class book:public publication {
    int page_count;
    
    public:
        void getdata() {
            publication::getdata();
            cin >> page_count;
        }
        
        void putdata() {
            publication::putdata();
            cout << "Book page count: " << page_count << endl;
        }
};

class tape:public publication {
    float minutes;
    
    public:
        void getdata() {
            publication::getdata();
            cin >> minutes;
        }
        
        void putdata() {
            publication::putdata();
            cout << "Tape's playing time: " << minutes << endl;
        }
};


int main()
{
    book b;
    tape t;
    b.getdata();
    cin.ignore();
    t.getdata();
    b.putdata();
    t.putdata();
}