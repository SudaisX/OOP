#include <iostream>
using namespace std;

void series(int t1, int t2, int n) {
    int next;

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            if (i == n) {
                cout << t1;
            } else {
                cout << t1 << ", ";
            }
        } else if (i == 1) {
            if (i == n) {
                cout << t2;
            } else {
                cout << t2 << ", ";
            }
        } else {
            next = t1 + t2;
            t1 = t2;
            t2 = next;

            if (i == n) {
                cout << next;
            } else {
                cout << next << ", ";
            }
        }
    }
}

int main(int argc, char** argv) {
    int term0, term1, n;
    std::cin >> term0 >> term1 >> n;
    series(term0, term1, n);
    return 0;
}
