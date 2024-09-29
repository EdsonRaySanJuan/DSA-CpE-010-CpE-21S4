#include <iostream>
using namespace std;

class Node {
    public:
        char data;   
        Node* next;  
};

void traverseList(Node* head) {
    Node* current = head;  
    while (current != NULL) {
        cout << current->data; // Output the data of the current node
        current = current->next; // Move to the next node
    }
    cout << endl;
}

void insertAtHead(Node*& head, char new_data) {
    Node* newNode = new Node; // Create a new node
    newNode->data = new_data; // Assign the new data ('G')
    newNode->next = head;     // Make the new node point to the old head
    head = newNode;           // Update head to point to the new node
}

void insertAtEnd(Node*& head, char new_data) {
    Node* newNode = new Node; // Create a new node
    newNode->data = new_data; // Assign data to the new node
    newNode->next = NULL;     // The new node will point to NULL as the last node

    if (head == NULL) {
        head = newNode;
        return;
    }

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
    insertAtEnd(head, '1');
    insertAtEnd(head, '0');
    insertAtEnd(head, '1');

    cout << "Traversing the linked list: ";
    traverseList(head);

    insertAtHead(head, 'G');

    cout << "After inserting 'G' at the start: ";
    traverseList(head);

    return 0;
}
