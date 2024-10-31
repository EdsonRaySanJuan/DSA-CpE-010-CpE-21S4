// SortingAlgorithms_7-4.h
#include <iostream>

// Function declaration for insertionSort
template <typename T>
void insertionSort(T arr[], const int N);

// Function definition for insertionSort
template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1;
    while (K < N) {
        T temp = arr[K];
        int J = K - 1;
        while (J >= 0 && temp < arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}

// Explicit instantiation for int type
template void insertionSort<int>(int arr[], const int N);
