#include <iostream>
using namespace std;

class Queue {
private:
    int* q_array;    
    int q_capacity;  
    int q_size;      
    int q_front;     
    int q_back;      

public:
    Queue(int capacity) {
        q_capacity = capacity;
        q_array = new int[q_capacity];
        q_size = 0;
        q_front = 0;  
        q_back = -1;  
    }

    ~Queue() {
        delete[] q_array;
    }

    bool isEmpty() {
        return q_size == 0;
    }

    bool isFull() {
        return q_size == q_capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = value;
        q_size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        int value = q_array[q_front];
        q_front = (q_front + 1) % q_capacity;
        q_size--;
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return an error value
        }
        return q_array[q_front];
    }

    int back() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        return q_array[q_back];
    }

    void displayContents() {
        cout << "Queue contents: ";
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < q_size; i++) {
            int index = (q_front + i) % q_capacity; // Use modulo to wrap around
            cout << q_array[index] << " ";
        }
        cout << endl; 
    }
};

int main() {
    Queue queue(7);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80); 

    queue.displayContents(); 

    cout << "Dequeued: " << queue.dequeue() << endl; 

    cout << "\nUpdated Queue contents: " << endl;
    queue.displayContents(); 
    cout << "\nFront element: " << queue.front() << endl; 
    cout << "Back element: " << queue.back() << endl;  

    return 0;
}
