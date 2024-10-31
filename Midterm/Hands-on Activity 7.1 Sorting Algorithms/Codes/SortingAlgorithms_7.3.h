// selectionSort.cpp
#include "SortingAlgorithms.h"

// Define Routine_Smallest
template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position = K;
    T smallestElem = A[K];
    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

// Define selectionSort, which uses Routine_Smallest
template <typename T>
void selectionSort(T arr[], const int N) {
    int POS;
    T temp;
    for (int i = 0; i < N; i++) {
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

// Explicit instantiations for the int type
template void selectionSort<int>(int arr[], const int N);
template int Routine_Smallest<int>(int A[], int K, const int arrSize);

