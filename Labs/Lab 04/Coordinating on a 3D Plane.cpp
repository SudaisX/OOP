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

struct Point {
    int x;
    int y;
    int z;

    void inputPoint() {
        cin >> x;
        cin >> y;
        cin >> z;
    }
};

Point pointAddition(Point p1, Point p2) {
    Point p;

    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    p.z = p1.z + p2.z;

    return p;
}

Point pointSubtraction(Point p1, Point p2) {
    Point p;

    p.x = p1.x - p2.x;
    p.y = p1.y - p2.y;
    p.z = p1.z - p2.z;

    return p;
}

Point pointMultiplication(Point p1, Point p2) {
    Point p;

    p.x = p1.x * p2.x;
    p.y = p1.y * p2.y;
    p.z = p1.z * p2.z;

    return p;
}

int main() {
    Point p1;
    p1.inputPoint();
    cout << "Coordinates of p1 are: (" << p1.x << ", " << p1.y << ", " << p1.z << ")" << endl;

    Point p2;
    p2.inputPoint();
    cout << "Coordinates of p2 are: (" << p2.x << ", " << p2.y << ", " << p2.z << ")" << endl;

    Point p3;
    p3 = pointAddition(p1, p2);
    cout << "Coordinates of p1 + p2 are: (" << p3.x << ", " << p3.y << ", " << p3.z << ")" << endl;

    p3 = pointSubtraction(p1, p2);
    cout << "Coordinates of p1 - p2 are: (" << p3.x << ", " << p3.y << ", " << p3.z << ")" << endl;

    p3 = pointMultiplication(p1, p2);
    cout << "Coordinates of p1 * p2 are: (" << p3.x << ", " << p3.y << ", " << p3.z << ")" << endl;

    return 0;
}
