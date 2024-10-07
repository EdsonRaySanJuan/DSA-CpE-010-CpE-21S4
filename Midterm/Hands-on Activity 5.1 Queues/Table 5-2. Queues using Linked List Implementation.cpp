#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next; 
};

class Queue {
private:
    Node* front;  
    Node* back;   

public:
    // Constructor
    Queue() {
        front = back = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertq(int value) {
        Node* newPtr = new Node(); 
        newPtr->data = value;      
        newPtr->next = NULL;      

        if (isEmpty()) {
            front = back = newPtr;
        } else {
            back->next = newPtr;
            back = newPtr;
        }

        cout << value << " has been inserted successfully." << endl;
    }

    void deleteq() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
            return;
        }
        
        Node* temp = front;
        cout << front->data << " has been deleted." << endl;
        front = front->next;

        if (front == NULL) {
            back = NULL; 
        }

        delete temp; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " "; 
            temp = temp->next;         
        }
        cout << endl;
    }
};

int main() {
    Queue q; 

    int initialValues[] = {2, 4, 1, 7};
    
    for (int value : initialValues) {
        q.insertq(value); 
    }

    q.insertq(3); 

    q.display();

    q.deleteq(); 

    q.display(); 

    q.deleteq();

    q.deleteq();
    q.deleteq(); 
    q.deleteq(); 

    q.deleteq(); 

    return 0; 
}
