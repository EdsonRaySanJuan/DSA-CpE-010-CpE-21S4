#include <iostream>
#include "link_list 6-3 b.h"

template <typename T>
Node<T>* new_node(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next = NULL;
    return node;
}

template <typename T>
Node<T>* getMiddle(Node<T>* head) {
    if (head == NULL)
        return NULL;

    Node<T>* slow = head;  
    Node<T>* fast = head;  

    // 1. Traverse the singly linked list using two pointers.**
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;           // 2. Move one pointer by one step ahead and the other pointer by two steps.**
        fast = fast->next->next;
    }

    return slow; // 3. When the fast pointer reaches the end of the singly linked list, the slow pointer will reach the middle of the singly linked list.**
                 // 4. Return slow pointer address.**
}

template <typename T>
Node<T>* binarySearchLinkedList(Node<T>* head, T key) {
    Node<T>* start = head;  
    Node<T>* end = NULL;    

    while (start != end) {
        Node<T>* middle = getMiddle(start);  

        if (middle->data == key) {
            return middle;  
        } 
        else if (middle->data < key) {
            start = middle->next;  
        } 
        else {
            end = middle;  
        }
    }

    return NULL;  
}
