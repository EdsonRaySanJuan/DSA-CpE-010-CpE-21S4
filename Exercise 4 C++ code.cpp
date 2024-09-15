#include <iostream>

class Node {
    public:
    int value;
    Node* next;
};

int main(){
    Node* head;
    Node* one;
    Node* two;
    Node* three;

    one = new Node();
    two = new Node();
    three = new Node();

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    while(head != NULL){
        std::cout << head->value << std::endl;
        head = head->next;
    }

    return 0;


}