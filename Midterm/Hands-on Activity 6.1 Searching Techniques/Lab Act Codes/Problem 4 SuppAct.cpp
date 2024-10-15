#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        cout << "Key not found" << endl;
        return -1;
    }

    int mid = low + (high - low) / 2;
    cout << "Low: " << low << ", High: " << high << ", Mid: " << mid << endl;

    if (arr[mid] == key) {
        cout << "\nKey found at index " << mid << endl;
        return mid;
    }
    else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, high, key);
    }
    else {
        return binarySearch(arr, low, mid - 1, key);
    }
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    int result = binarySearch(arr, 0, n - 1, key);
    return 0;
}
