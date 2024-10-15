// main
#include <iostream>
#include "searching 6-3a.h"
using namespace std;

// Function definition for binary search
void binarySearch(int arr[], int n, int key) {
    int low = 0;
    int up = n - 1;

    while (low <= up) {
        int mid = (low + up) / 2;  // Calculate the middle index

        if (arr[mid] == key) {     // If the middle element is the key
            cout << "Search element is found!" << endl;
            return;
        } else if (key < arr[mid]) {  // If key is less, search in the left half
            up = mid - 1;
        } else {                      // If key is greater, search in the right half
            low = mid + 1;
        }
    }
    cout << "Search element is not found" << endl;
}

int main() {
    int arr[] = {0, 2, 5, 8, 12, 18, 22, 27, 33, 45}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    // Call the binary search function
    binarySearch(arr, n, key);

    return 0;
}


