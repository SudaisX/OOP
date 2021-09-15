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

void input_years(int yrs[], int num_yrs);
void print_yrs_array(int yrs[], int num_yrs);
void chronological_order(int yrs[], int num_yrs);

int main() {
    int num_yrs;
    while (true) {
        cin >> num_yrs;
        if (num_yrs >= 2) {
            break;
        }
        cout << "Need at least 2 years to sort! Try Again!" << endl;
    }
    int yrs[num_yrs];
    input_years(yrs, num_yrs);

    cout << "The initial array is: ";
    print_yrs_array(yrs, num_yrs);
    chronological_order(yrs, num_yrs);

    return 0;
}

void input_years(int yrs[], int num_yrs) {
    for (int i = 0; i < num_yrs; i++) {
        while (true) {
            cin >> yrs[i];
            if (yrs[i] >= 0 && yrs[i] <= 9999) {
                break;
            }
            cout << "Year can be between 0 and 9999! Try Again!" << endl;
        }
    }
}

void print_yrs_array(int yrs[], int num_yrs) {
    for (int i = 0; i < num_yrs - 1; i++) {
        cout << yrs[i] << ", ";
    }
    cout << yrs[num_yrs - 1] << endl;
}

void chronological_order(int yrs[], int num_yrs) {
    int temp;
    for (int i = 0; i < (num_yrs - 1); i++) {
        for (int j = 0; j < (num_yrs - i - 1); j++) {
            if (yrs[j] > yrs[j + 1]) {
                temp = yrs[j];
                yrs[j] = yrs[j + 1];
                yrs[j + 1] = temp;
            }
        }
    }
    // sort(yrs, yrs + num_yrs);
    cout << "The sorted array is: ";
    print_yrs_array(yrs, num_yrs);
}
