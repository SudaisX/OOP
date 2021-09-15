#include <iostream>
using namespace std;

void input_matrix(int arr[], int r, int c);
void add_matrix(int arr1[], int arr2[], int arr3[], int r, int c);
void subtract_matrix(int arr1[], int arr2[], int arr3[], int r, int c);
void print_matrix(int arr[], int r, int c);

int main() {
    int r, c;
    cin >> r >> c;

    int arr1[c * r], arr2[c * r], arr3[c];

    input_matrix(arr1, r, c);
    input_matrix(arr2, r, c);

    char op;
    cin >> op;

    if (op == '+') {
        add_matrix(arr1, arr2, arr3, r, c);
        print_matrix(arr3, r, c);
    } else if (op == '-') {
        subtract_matrix(arr1, arr2, arr3, r, c);
        print_matrix(arr3, r, c);
    }
    return 0;
}

void input_matrix(int arr[], int r, int c) {
    for (int i = 0; i < r * c; i++) {
        cin >> arr[i];
    }
};

void add_matrix(int arr1[], int arr2[], int arr3[], int r, int c) {
    for (int i = 0; i < r * c; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}

void subtract_matrix(int arr1[], int arr2[], int arr3[], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = c * i; j < c * (i + 1); j++) {
            arr3[j] = arr1[j] - arr2[j];
        }
    }
}

void print_matrix(int arr[], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = c * i; j < c * (i + 1); j++) {
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
}