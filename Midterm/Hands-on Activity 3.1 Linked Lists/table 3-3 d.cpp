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
        cout << current->data; 
        current = current->next; 
    }
    cout << endl;
}

void insertAtHead(Node*& head, char new_data) {
    Node* newNode = new Node; 
    newNode->data = new_data; 
    newNode->next = head;     
    head = newNode;           
}

void insertAtEnd(Node*& head, char new_data) {
    Node* newNode = new Node; 
    newNode->data = new_data; 
    newNode->next = NULL;     

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

void insertAfter(Node* prev_node, char new_data) {
    if (prev_node == NULL) {
        cout << "The previous node cannot be NULL." << endl;
        return;
    }
    
    Node* newNode = new Node; 
    newNode->data = new_data; 
    newNode->next = prev_node->next; 
    prev_node->next = newNode; 
}

// Delete the node containing the element C.
void deleteNode(Node*& head, char value) {
    Node* current = head; 
    Node* prev = NULL;    

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            head = current->next; 
        } else {
            prev->next = current->next; 
        }
        delete current; // Free the memory of the deleted node
    } else {
        cout << "Node with value '" << value << "' not found." << endl;
    }
}

int main() {
    Node* head = NULL;  

    insertAtEnd(head, 'C');
    insertAtEnd(head, 'P');
    insertAtEnd(head, 'E');
    insertAtEnd(head, '1');
    insertAtEnd(head, '0');
    insertAtEnd(head, '1');

    insertAtHead(head, 'G');

    Node* current = head;
    while (current != NULL) {
        if (current->data == 'P') {
            insertAfter(current, 'E'); 
            break;
        }
        current = current->next;
    }

    cout << "Before deleting 'C': ";
    traverseList(head);

    deleteNode(head, 'C'); // Deleting the node containing 'C'

    cout << "After deleting 'C': ";
    traverseList(head);

    return 0;
}
