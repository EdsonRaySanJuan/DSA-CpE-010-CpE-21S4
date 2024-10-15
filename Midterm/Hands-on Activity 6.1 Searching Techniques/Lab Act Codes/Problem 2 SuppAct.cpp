#include <iostream>

using namespace std;

// Array approach
int seqSearchA(int arr[], int size, int key) {
    int count = 0; // Initialize count of occurrences
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++; // Increment count if key is found
        }
    }
    return count; // Return the total count of occurrences
}

// Linked list approach
struct Node {
    int data;
    Node* next;
};

int seqSearchLL(Node* head, int key) {
    int count = 0; // Initialize count of occurrences
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++; // Increment count if key is found
        }
        current = current->next; // Move to the next node
    }
    return count; // Return the total count of occurrences
}

int main() {
    // Array approach
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    int countArray = seqSearchA(arr, size, key);
    cout << "Number of occurrences of " << key << " in array: " << countArray << endl;
    
    // Linked list approach
    int arr2[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    Node* head = NULL;
    Node** current = &head;
    
    for (int i = 0; i < size2; i++) {
        *current = new Node();
        (*current)->data = arr2[i]; 
        (*current)->next = NULL;
        current = &((*current)->next);
    }
    
    int countLinkedList = seqSearchLL(head, key);
    cout << "Number of occurrences of " << key << " in linked list: " << countLinkedList << endl;

    return 0;
}
