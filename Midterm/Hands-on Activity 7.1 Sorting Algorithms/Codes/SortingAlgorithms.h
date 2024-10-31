// SortingAlgorithms.h
#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

class SortingAlgorithms {
public:
    // Bubble Sort
    static void bubbleSort(int arr[], int size);
    
    // Insertion Sort
    static void insertionSort(int arr[], int size);
    
    // Selection Sort
    static void selectionSort(int arr[], int size);
    
    // Merge Sort
    static void mergeSort(int arr[], int left, int right);
    
    // Quick Sort
    static void quickSort(int arr[], int left, int right);

private:
    // Helper function for Merge Sort to merge two subarrays
    static void merge(int arr[], int left, int mid, int right);
    
    // Helper function for Quick Sort to partition the array
    static int partition(int arr[], int left, int right);
};

#endif // SORTINGALGORITHMS_H

