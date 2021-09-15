#include <iostream>
using namespace std;

int string_length(string string) {
    int count = 0;
    while (string[count] != '\0') {
        count += 1;
    }
    return count;
}

int main() {
    string string;
    getline(cin, string);
    cout << string_length(string);
}