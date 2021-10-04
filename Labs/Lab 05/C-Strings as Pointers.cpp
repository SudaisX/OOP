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
int cstr_len(char *cstr);
void append_cstrings(char *dest, char *src1, char *src2);
void toggle_case(char *cstr);

int main() {
    int MAX = 100;
    char str1[MAX];
    cin.getline(str1, MAX);
    char str2[MAX];
    cin.getline(str2, MAX);
    char dest[cstr_len(str1) + cstr_len(str2)];

    append_cstrings(str1, str2, dest);
    cout << "\"" << str1 << "\""
         << " + "
         << "\"" << str2 << "\""
         << " = "
         << "\"" << dest << "\"" << endl;

    toggle_case(dest);
    cout << "After case reversal: \"" << dest << "\"";

    return 0;
}

int cstr_len(char *cstr) {
    int i = 0;
    while (cstr[i] != '\0') {
        i++;
    }
    return i;
}

void append_cstrings(char *src1, char *src2, char *dest) {
    int src1Len = cstr_len(src1);
    int src2Len = cstr_len(src2);

    for (int i = 0; i < src1Len; i++) {
        dest[i] = src1[i];
    }
    dest[src1Len] = ' ';
    for (int i = 0; i < src2Len + 1; i++) {
        dest[i + src1Len + 1] = src2[i];
    }
}

void toggle_case(char *cstr) {
    int size = cstr_len(cstr);

    for (int i = 0; i < size; i++) {
        int asci = int(cstr[i]);
        if (asci >= 65 && asci <= 90) {
            cstr[i] = char(asci + 32);
        } else if (asci >= 97 && asci <= 122) {
            cstr[i] = char(asci - 32);
        }
    }
}