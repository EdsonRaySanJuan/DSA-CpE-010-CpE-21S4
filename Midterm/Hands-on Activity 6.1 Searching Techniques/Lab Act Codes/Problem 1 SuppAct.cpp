#include <iostream>

using namespace std;

// Array approach
void seqSearchA(int arr[], int size, int key) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            cout << "Key found at index " << i << " in " << comparisons << " comparisons." << endl;
            return;
        }
    }
    cout << "Key not found in " << comparisons << " comparisons." << endl;
}

// Linked list approach
struct Node {
    int data;
    Node* next;
};

void seqSearchLL(Node* head, int key) {
    int comparisons = 0;
    Node* current = head;
    while (current != NULL) {
        comparisons++;
        if (current->data == key) {
            cout << "Key found in " << comparisons << " comparisons." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Key not found in " << comparisons << " comparisons." << endl;
}

int main() {
    // Array approach
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    seqSearchA(arr, size, key);
    
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
    
    seqSearchLL(head, key);

    return 0;
}
