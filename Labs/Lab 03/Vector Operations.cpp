#include <iostream>
using namespace std;

void input_vector(int arr[], int size);
void add_vectors(int arr1[], int arr2[], int arr3[], int size);
void subtract_vectors(int arr1[], int arr2[], int arr3[], int size);
bool compare_vectors(int arr1[], int arr2[], int size);
void print_vector(int arr[], int size);

int main() {
    int size;
    cin >> size;

    int arr1[size], arr2[size], arr3[size];

    input_vector(arr1, size);
    input_vector(arr2, size);

    char op;
    cin >> op;
    if (op == '+') {
        add_vectors(arr1, arr2, arr3, size);
        print_vector(arr3, size);
    } else if (op == '-') {
        subtract_vectors(arr1, arr2, arr3, size);
        print_vector(arr3, size);
    } else if (op == '=') {
        if (compare_vectors(arr1, arr2, size)) {
            cout << "EQUAL";
        } else {
            cout << "UNEQUAL";
        }
    }
    return 0;
}

void input_vector(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
};

void add_vectors(int arr1[], int arr2[], int arr3[], int size) {
    for (int i = 0; i < size; i++) {
        arr3[i] = (arr1[i] + arr2[i]);
    }
};

void subtract_vectors(int arr1[], int arr2[], int arr3[], int size) {
    for (int i = 0; i < size; i++) {
        arr3[i] = (arr1[i] - arr2[i]);
    }
};

bool compare_vectors(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void print_vector(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
