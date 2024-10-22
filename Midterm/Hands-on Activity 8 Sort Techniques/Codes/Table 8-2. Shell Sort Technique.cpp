// main.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; // Correct placement of the using directive

void generateRandomArray(int arr[], int size) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int array[], int size) {
    int interval = size / 2; // Start with a large interval

    while (interval > 0) {
        for (int i = interval; i < size; i++) {
            int temp = array[i];
            int j = i;

            // Insertion sort for the interval
            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp; // Insert the element at the correct position
        }
        interval /= 2; // Reduce the interval
    }
}

int main() {
    const int size = 100; 
    int randomArray[size];

    generateRandomArray(randomArray, size);
    cout << "Random Array: ";
    printArray(randomArray, size);

    shellSort(randomArray, size);
    cout << "\nSorted Array: ";
    printArray(randomArray, size);

    return 0;
}
