// main.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 

void generateRandomArray(int arr[], int size) {
    // Seed the random number generator
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Using cout from the standard namespace
    }
    cout << endl;
}

int main() {
    const int size = 100; 
    int randomArray[size];
    
    generateRandomArray(randomArray, size);
    cout << "Random Array: ";
    printArray(randomArray, size);
    
    return 0;
}
