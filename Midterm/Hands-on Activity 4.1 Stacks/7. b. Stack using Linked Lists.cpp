// b. Stack using Linked Lists 

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

class Stack {
    private:
    Node* top;
    
    public:
    Stack() {
    top = nullptr;
    }
    // Push a character onto the stack
    void push(char character) {
        Node* newNode = new Node();
        newNode->data = character;
        newNode->next = top;
        top = newNode;
    }
    // Pop a character from the stack
    char pop() {
        if (top == nullptr) {
            cout << "Error: Stack is empty." << endl;
            return '\0'; // null character, represents the end of a string
        }
        char character = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return character;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};
// Function to balance symbols
void check_if_Balance(char* input) {
    Stack stack;
    int i = 0;
    // While(end of input is not reached)
    while (input[i] != '\0') {
        // a) If the character read is not a symbol to be balanced, ignore it. 
        // b) If the character is an opening symbol, push it onto the stack. 
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
            stack.push(input[i]);
        }
        // c) If it is a closing symbol
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
            //     i) Report an error if the stack is empty. 
            if (stack.isEmpty()) {
                cout << "Error: Unbalanced symbol " << input[i] << endl;
                return;
            }
            //     ii) Otherwise, pop the stack. 
            char topSymbol = stack.pop();
            if ((input[i] == ')' && topSymbol != '(') ||
                (input[i] == '}' && topSymbol != '{') ||
                (input[i] == ']' && topSymbol != '[')) {
                // Print an error message if the symbols do not match
                cout << "Error: Unbalanced symbol " << input[i] << endl;
                return;
            }
        }
        // Increment the index to move to the next character in the input string
        i++;
    }
    // d) If the symbol popped is not the corresponding opening symbol, report an error. 
    if (!stack.isEmpty()) {
        cout << "Error: Unbalanced symbol. Stack is not empty" << endl;
    } else {
        cout << "Symbols are balanced" << endl;
    }
}

int main() {
    char input[] = "({[]})";
    check_if_Balance(input);
    return 0;
}