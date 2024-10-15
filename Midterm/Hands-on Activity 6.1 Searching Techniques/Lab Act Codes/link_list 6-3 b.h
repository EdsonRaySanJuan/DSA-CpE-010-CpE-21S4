#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
Node<T>* new_node(T data);

template <typename T>
Node<T>* getMiddle(Node<T>* head);

template <typename T>
Node<T>* binarySearchLinkedList(Node<T>* head, T key);

#include "link_list 6-3 b.cpp" 

#endif
