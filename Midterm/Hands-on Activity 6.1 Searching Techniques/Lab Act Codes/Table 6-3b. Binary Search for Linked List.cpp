#include <iostream>
#include "link_list 6-3 b.h"

int main() {
    char choice = 'y';
    int newData;
    Node<int>* temp, *head = NULL, *node = NULL;

    int numberOfElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;

    for (int count = 0; count < numberOfElements;) {
        std::cout << "Enter data: ";
        std::cin >> newData;

        node = new_node(newData);
        if (head == NULL) {
            head = node;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
        std::cout << "Successfully added " << node->data << " to the list.\n";
        count++;

        if (count < numberOfElements) {
            do {
                std::cout << "Do you want to continue? (y/n): ";
                std::cin >> choice;

                if (choice != 'y' && choice != 'n') {
                    std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                }
            } while (choice != 'y' && choice != 'n');

            if (choice == 'n') {
                break;
            }
        }
    }

    temp = head;
    std::cout << "Linked list: ";
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";

    int key;
    std::cout << "Enter a number to search: ";
    std::cin >> key;

    Node<int>* result = binarySearchLinkedList(head, key);
    if (result != NULL) {
        std::cout << "Found " << key << " in the list.\n";
    } else {
        std::cout << "Did not find " << key << " in the list.\n";
    }

    return 0;
}
