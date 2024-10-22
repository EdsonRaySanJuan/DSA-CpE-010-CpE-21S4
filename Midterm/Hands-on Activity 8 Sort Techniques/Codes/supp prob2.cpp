// main.cpp
#include <iostream>
#include "sortAlgo_prob2-supp.h"
using namespace std;

int main() {
    int arr[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Display original array
    cout << "Original Array:" << endl;
    displayArray(arr, size);

    // Sort using Bubble Sort
    int bubbleSortedArray[15];
    for (int i = 0; i < size; i++) {
        bubbleSortedArray[i] = arr[i];
    }
    bubbleSort(bubbleSortedArray, size);
    cout << "Sorted Array using Bubble Sort:" << endl;
    displayArray(bubbleSortedArray, size);

    // Sort using Selection Sort
    int selectionSortedArray[15];
    for (int i = 0; i < size; i++) {
        selectionSortedArray[i] = arr[i];
    }
    selectionSort(selectionSortedArray, size);
    cout << "Sorted Array using Selection Sort:" << endl;
    displayArray(selectionSortedArray, size);

    // Sort using Insertion Sort
    int insertionSortedArray[15];
    for (int i = 0; i < size; i++) {
        insertionSortedArray[i] = arr[i];
    }
    insertionSort(insertionSortedArray, size);
    cout << "Sorted Array using Insertion Sort:" << endl;
    displayArray(insertionSortedArray, size);

    // Sort using Merge Sort
    int mergeSortedArray[15];
    for (int i = 0; i < size; i++) {
        mergeSortedArray[i] = arr[i];
    }
    mergeSort(mergeSortedArray, 0, size - 1);
    cout << "Sorted Array using Merge Sort:" << endl;
    displayArray(mergeSortedArray, size);

    // Sort using Shell Sort
    int shellSortedArray[15];
    for (int i = 0; i < size; i++) {
        shellSortedArray[i] = arr[i];
    }
    shellSort(shellSortedArray, size);
    cout << "Sorted Array using Shell Sort:" << endl;
    displayArray(shellSortedArray, size);

    // Sort using Quick Sort
    int quickSortedArray[15];
    for (int i = 0; i < size; i++) {
        quickSortedArray[i] = arr[i];
    }
    quickSort(quickSortedArray, 0, size - 1);
    cout << "Sorted Array using Quick Sort:" << endl;
    displayArray(quickSortedArray, size);

    return 0;
}