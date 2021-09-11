#include <iostream>
using namespace std;

int countHoles(int num) {
    int currNum, holes = 0;

    while (num > 0) {
        currNum = num % 10;
        num /= 10;

        if (currNum == 0 || currNum == 4 || currNum == 6 || currNum == 9) {
            holes++;
        } else if (currNum == 8) {
            holes += 2;
        }
    }
    return holes;
}

int main() {
    int num;
    cin >> num;
    cout << countHoles(num) << " holes";
    return 0;
}