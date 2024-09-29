#include <iostream>
using namespace std;

class Node {
public:
    char data;      // Data part of the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize the node
    Node(char value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;    // Pointer to the first node (head)
    Node* tail;    // Pointer to the last node (tail)

public:
    // Constructor to initialize the list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a node at the end
    void insertAtEnd(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the list from the head to the tail
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the list from the tail to the head
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert nodes into the list
    list.insertAtEnd('4');
    list.insertAtEnd('5');
    list.insertAtEnd('6');
    list.insertAtEnd('7');

    // Display the list in forward and backward directions
    cout << "List in forward direction: ";
    list.displayForward();

    cout << "List in backward direction: ";
    list.displayBackward();

    return 0;
}
