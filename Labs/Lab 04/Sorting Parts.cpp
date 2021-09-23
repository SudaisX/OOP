#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Part {
    int modelNumber;
    int year;
    int price;
};

void input(Part parts[], int N);
void sort(Part parts[], int N);
void display(Part parts[], int N);

int main() {
    int size;
    cin >> size;
    Part parts[size];

    input(parts, size);
    sort(parts, size);
    display(parts, size);

    return 0;
}

void input(Part parts[], int N) {
    for (int i = 0; i < N; i++) {
        cin >> parts[i].price;
        cin >> parts[i].modelNumber;
        cin >> parts[i].year;
    }
}

void display(Part parts[], int N) {
    for (int i = 0; i < N; i++) {
        cout << "Price: " << parts[i].price << ", Part No.: " << parts[i].modelNumber << ", Part Model: " << parts[i].year << endl;
    }
}

void sort(Part parts[], int N) {
    Part temp;
    for (int i = 0; i < (N - 1); i++) {
        for (int j = 0; j < (N - i - 1); j++) {
            if (parts[j].price > parts[j + 1].price) {
                temp = parts[j];
                parts[j] = parts[j + 1];
                parts[j + 1] = temp;
            }
        }
    }
}