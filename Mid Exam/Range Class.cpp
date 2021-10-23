#include <iostream>
using namespace std;

class range {
   public:
    int start;
    int end;
    int step;

    // Constructors
    range() : start(0), end(0), step(1) {}

    range(int endNum) : start(0), end(endNum), step(1) {}
    range(int startNum, int endNum) : start(startNum), end(endNum), step(1) {}
    range(int startNum, int endNum, int stepNum) : start(startNum), end(endNum), step(stepNum) {}

    // Methods
    int length() {
        int l = max(0, (end - start + step - 1) / step);
        return l;
    }

    int* getList() {
        int* list = new int[end];
        int count = 0;
        if (step > 0) {
            for (int i = start; i < end; i += step) {
                list[count] = i;
                count += 1;
            }
        } else {
            for (int i = start; i > end; i += step) {
                list[count] = i;
                count += 1;
            }
        }

        return list;
    }

    // Operator Overloading
    friend ostream& operator<<(ostream& output, range& r) {
        int* list = r.getList();
        for (int i = 0; i < r.length(); i++) {
            output << list[i] << " ";
        }
        output << endl;
        return output;
    }

    void operator+=(int num) {
        end += num;
    }

    void operator[](int num) {
        int* list = getList();
        if (num < 0) {
            int index = length() + num;
            cout << list[index] << endl;
        } else {
            cout << list[num] << endl;
        }
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout << "Range Elements\n=============\n";
    range r(0, 50, 5);
    cout << r;
    cout << " Number of elements in a range : " << r.length() << "\n";
    cout << " Value at index 9 : ";
    r[9];
    cout << " Value at index -7 : ";
    r[-7];
    r += 8;
    cout << r;
    cout << " Number of elements in a range : " << r.length() << "\n";
    cout << " Value at index 11 : ";
    r[11];
    cout << " Value at index -5 : ";
    r[-5];

    cout << "\nRange Elements\n=============\n";
    range r2(20, 10, -1);
    cout << r2;
    cout << " Number of elements in a range : " << r2.length() << "\n";
    cout << " Value at index 6 : ";
    r2[6];
    cout << " Value at index -4 : ";
    r2[-4];
    r2 += 8;
    cout << r2;
    cout << " Number of elements in a range : " << r2.length() << "\n";
    cout << " Value at index 18 : ";
    r2[18];
    cout << " Value at index -18 : ";
    r2[-18];

    cout << "\nRange Elements\n=============\n";
    range r3(10);  // 0 10 1
    cout << r3;
    cout << " Number of elements in a range : " << r3.length() << "\n";
    cout << " Value at index 6 : ";
    r3[6];
    cout << " Value at index -5 : ";
    r3[-5];
    r3 += 8;
    cout << r3;
    cout << " Number of elements in a range : " << r3.length() << "\n";
    cout << " Value at index 18 : ";
    r3[18];
    cout << " Value at index -4 : ";
    r3[-4];

    return 0;
}