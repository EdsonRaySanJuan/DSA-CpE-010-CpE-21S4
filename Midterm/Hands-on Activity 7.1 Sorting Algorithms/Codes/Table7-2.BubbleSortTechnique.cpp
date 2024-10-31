// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithms.h" // Import the header file

using namespace std;

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize - 1; i++) {
        for (size_t j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }

    cout << "Original array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, SIZE);

    cout << "\nSorted array (Bubble Sort): ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

