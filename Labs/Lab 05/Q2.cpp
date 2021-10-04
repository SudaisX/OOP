#include <iostream>
using namespace std;

// int count = 0;
// void callMe() {
//     count += 1;
//     cout << "I have been called " << count << " times" << endl;
// }

void callMe() {
    static int count = 0;
    count += 1;

    cout << "I have been called " << count << " times" << endl;
}

int main() {
    for (int i = 0; i < 10; i++) {
        callMe();
    }
}

// Cant use just local variables because they lose their memory after being called once