// main.cpp

#include "searching a.h"

int main() {
    // Create a linked list with the name "Roman"
    Node<char>* name1 = new_node('r');
    Node<char>* name2 = new_node('o');
    Node<char>* name3 = new_node('m');
    Node<char>* name4 = new_node('a');
    Node<char>* name5 = new_node('n');

    // Link each node to each other
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = NULL;

    // Perform linear search
    linearSearch(name1, 'n');

    return 0;
}
