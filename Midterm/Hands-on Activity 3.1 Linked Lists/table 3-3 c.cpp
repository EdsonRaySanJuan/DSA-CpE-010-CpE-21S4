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
    newNode->data = new_data; // Assign the new data ('G')
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
    newNode->data = new_data; // Assign the new data ('E')
    newNode->next = prev_node->next; 
    prev_node->next = newNode; 
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

    cout << "After inserting 'G' at the start: ";
    traverseList(head);

    Node* current = head;
    while (current != NULL) {
        if (current->data == 'P') {
            insertAfter(current, 'E'); // Insert 'E' after 'P'
            break;
        }
        current = current->next;
    }

    cout << "After inserting 'E' after 'P': ";
    traverseList(head);

    return 0;
}
