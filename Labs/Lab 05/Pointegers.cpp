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

void sort_arr(int* arr1, int sz);
int binary_search(int* arr1, int val, int sz);

int main() {
    // Input Array Size
    int arrLen;
    cin >> arrLen;
    while (arrLen <= 0) {
        cout << "Incorrect size! Try Again" << endl;
        cin >> arrLen;
    }

    // Declare Array
    int arr[arrLen];
    // Array input
    for (int i = 0; i < arrLen; i++) {
        cin >> arr[i];
    }

    // Input Value to be searched
    int val;
    cin >> val;

    // Print Unsorted Array
    cout << "Before sorting: ";
    for (int i = 0; i < arrLen - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[arrLen - 1] << endl;

    // Sort Array
    sort_arr(arr, arrLen);

    // Print Sorted Array
    cout << "After sorting: ";
    for (int i = 0; i < arrLen - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[arrLen - 1] << endl;

    // Print value to be searched
    cout << "\n"
         << "The value to be searched: " << val << endl;
    int index = binary_search(arr, val, arrLen);
    if (index == -1) {
        cout << "Element is not present in the array!";
    } else {
        cout << "Element is present at index: " << index;
    }

    return 0;
}

void sort_arr(int* arr1, int sz) {
    int temp;
    for (int i = 0; i < (sz - 1); i++) {
        for (int j = 0; j < (sz - i - 1); j++) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
}

int binary_search(int* arr1, int val, int sz) {
    int low = 0;
    while (low <= sz) {
        int mid = low + (sz - 1) / 2;
        if (arr1[mid] == val) {
            return mid;
        } else if (arr1[mid] > val) {
            sz = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
