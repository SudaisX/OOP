#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
    int base, exponent, num = 1;

    cin >> base;
    cin >> exponent;

    if (base >= 1 && base <= 10 && exponent >= 0 && exponent <= 5) {
        for (int i = 0; i < exponent; i++) {
            num *= base;
        }
        cout << base << " to the power of " << exponent << " is: " << num << endl;
    } else {
        cout << "Invalid input!" << endl;
    }

    return 0;
}