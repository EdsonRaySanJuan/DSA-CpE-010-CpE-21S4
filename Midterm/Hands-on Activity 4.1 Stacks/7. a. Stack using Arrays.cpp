#include <iostream>
#include <stack> // Create a Stack. 
using namespace std;

const int MAX_SIZE = 10;
int top = -1;

// Define an array to store the stack elements
char stackData[MAX_SIZE]; 

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(char symbol) {
    if (isFull()) {
        cout << "Stack is full. Cannot push " << symbol << endl;
        return;
    }
    // Increment the top index and store the symbol at the new top index
    stackData[++top] = symbol;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop" << endl;
        return '\0';
    }
    // Decrement the top index and return the symbol at the previous top index
    return stackData[top--];
}

char getTop() {
    if (isEmpty()) {
        cout << "Stack is empty. No top element" << endl;
        return '\0';
    }
    // Return the symbol at the current top index
    return stackData[top];
}

void checkBalance(char* input) {
    int i = 0;
    // While(end of input is not reached)
    while (input[i] != '\0') {
        // a) If the character read is not a symbol to be balanced, ignore it. 
        // b) If the character is an opening symbol, push it onto the stack. 
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
            push(input[i]);
        }
        // c) If it is a closing symbol
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
            //     i) Report an error if the stack is empty. 
            if (isEmpty()) {
                cout << "Error: Unbalanced symbol " << input[i] << endl;
                return;
            }
            //     ii) Otherwise, pop the stack. 
            char topSymbol = pop();
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
    if (!isEmpty()) {
        cout << "Error: Unbalanced symbol. Stack is not empty" << endl;
    } else {
        cout << "Symbols are balanced" << endl;
    }
}

int main() {
    char input[] = "({[]})";
    checkBalance(input);
    return 0;
}