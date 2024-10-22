// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortAlgo.h"
using namespace std;

int main() {
    srand(time(0));  // Seed for random number generation

    const int size = 100;
    int arr[size];

    // Generate random array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Random values between 0 and 99
    }

    // Display the generated random array
    cout << "Random Array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // Apply sorting algorithms
    int arrBubble[size];
    int arrSelection[size];
    int arrInsertion[size];
    int arrShell[size];
    int arrMerge[size];
    int arrQuick[size];

    for (int i = 0; i < size; i++) {
        arrBubble[i] = arr[i];
        arrSelection[i] = arr[i];
        arrInsertion[i] = arr[i];
        arrShell[i] = arr[i];
        arrMerge[i] = arr[i];
        arrQuick[i] = arr[i];
    }

    bubbleSort(arrBubble, size);
    selectionSort(arrSelection, size);
    insertionSort(arrInsertion, size);
    shellSort(arrShell, size);
    mergeSort(arrMerge, 0, size - 1);
    quickSort(arrQuick, 0, size - 1);

    // Display the sorted arrays
    cout << "Sorted Arrays:" << endl;
    cout << "\nBubble Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arrBubble[i] << " ";
    }
    cout << endl;

    cout << "\nSelection Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arrSelection[i] << " ";
    }
    cout << endl;

    cout << "\nInsertion Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arrInsertion[i] << " ";
    }
    cout << endl;

    cout << "\nShell Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arrShell[i] << " ";
    }
    cout << endl;

    cout << "\nMerge Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arrMerge[i] << " ";
    }
    cout << endl;

    cout << "\nQuick Sort: ";
    for (int i = 0; i < size; i++) {
        cout << arrQuick[i] << " ";
    }
    cout << endl;

    return 0;
}