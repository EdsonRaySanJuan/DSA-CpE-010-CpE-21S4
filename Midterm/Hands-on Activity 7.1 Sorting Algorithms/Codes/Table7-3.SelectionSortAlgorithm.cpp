// main.cpp
#include <iostream>
#include "SortingAlgorithms_7.3.h"

int main() {
    int arr[] = {5, 2, 8, 3, 1, 6, 4};
    const int N = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before sorting: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(arr, N);

    std::cout << "After sorting: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
