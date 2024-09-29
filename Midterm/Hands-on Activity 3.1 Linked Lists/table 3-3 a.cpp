#include <iostream>
using namespace std;

class Node {
    public:
        char data;   
        Node* next; 
};

void traverseList(Node* head) {
    Node* current = head;  // Start with the head node
    while (current != NULL) {
        cout << current->data << " "; // Output the data of the current node
        current = current->next;      // Move to the next node
    }
    cout << endl;
}

void insertAtEnd(Node*& head, char new_data) {
    Node* newNode = new Node; // Create a new node
    newNode->data = new_data; // Assign data to the new node
    newNode->next = NULL;     // The new node will point to NULL as the last node

    // If list is empty, the new node becomes the head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Find the last node and attach the new node at the end
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

int main() {
    Node* head = NULL;  

    insertAtEnd(head, 'C');
    insertAtEnd(head, 'P');
    insertAtEnd(head, 'E');
    insertAtEnd(head, '0');
    insertAtEnd(head, '1');
    insertAtEnd(head, '0');



    cout << "Traversing the linked list: ";
    traverseList(head);

    return 0;
}