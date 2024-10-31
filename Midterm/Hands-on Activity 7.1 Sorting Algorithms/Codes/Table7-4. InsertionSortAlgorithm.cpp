// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithms_7-4.h" // Include the merged file

using namespace std;

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0))); 

    // Generate random numbers between 0 and 999
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 1000; 
    }

    cout << "Original array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " "; // Add a space between numbers
    }
    cout << endl;

    // Sort the array using InsertionSort
    insertionSort(arr, SIZE);

    cout << "\nSorted array (Insertion Sort): ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " "; // Add a space between numbers
    }
    cout << endl;

    return 0;
}
