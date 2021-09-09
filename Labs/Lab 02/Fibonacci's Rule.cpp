#include <iostream>
using namespace std;

void printTerm(int i, int n, int term) {
    if (i == n) {
        cout << term;
    } else {
        cout << term << ", ";
    }
}

void series(int t1, int t2, int n) {
    int next;

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            printTerm(i, n, t1);
        } else if (i == 1) {
            printTerm(i, n, t2);
        } else {
            next = t1 + t2;
            t1 = t2;
            t2 = next;
            printTerm(i, n, next);
        }
    }
}

int main(int argc, char** argv) {
    int term0, term1, n;
    std::cin >> term0 >> term1 >> n;
    series(term0, term1, n);
    return 0;
}
