// main.cpp
#include <iostream>
#include <cstdlib>
#include "sortAlgo.h"
using namespace std;

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Step 1: Perform Quick Sort to partition the array
    quickSort(arr, 0, size - 1);

    // Display the array after Quick Sort
    cout << "Array after Quick Sort (partitioned):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Step 2: Sort the left sublist using Bubble Sort
    int leftSublistSize = 5; // Size of the left sublist
    int leftSublist[5] = {34, 7, 23, 32, 5}; // Left sublist

    bubbleSort(leftSublist, leftSublistSize);

    // Display the sorted left sublist
    cout << "Sorted Left Sublist using Bubble Sort:" << endl;
    for (int i = 0; i < leftSublistSize; i++) {
        cout << leftSublist[i] << " ";
    }
    cout << endl;

    return 0;
}