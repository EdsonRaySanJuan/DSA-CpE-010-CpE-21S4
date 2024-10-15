// searching.h

#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* new_node(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next = NULL;
    return node;
}

template <typename T>
bool linearSearch(Node<T>* head, T item) {
    Node<T>* current = head;

    while (current != NULL) {
        if (current->data == item) {
            cout << "Searching is successful" << endl;
            return true;
        }
        current = current->next;
    }

    cout << "Searching is unsuccessful" << endl;
    return false;
}

#endif  // SEARCHING_H
