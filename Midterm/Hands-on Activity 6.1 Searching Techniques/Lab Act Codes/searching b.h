// binary_search.h

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

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
int countNodes(Node<T>* head) {
    int count = 0;
    Node<T>* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
int binarySearch(Node<T>* head, T no) {
    int n = countNodes(head);
    int low = 0;
    int up = n - 1;

    while (low <= up) {
        int mid = (low + up) / 2;

        Node<T>* temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        if (temp->data == no) {
            cout << "Search element is found!" << endl;
            return mid;
        } else if (no < temp->data) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << "Search element is not found" << endl;
    return -1;
}

#endif  // BINARY_SEARCH_H
