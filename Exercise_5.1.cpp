#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 3;

void display(stack<string> pl) {
    // Check if the stack is full
    if (pl.size() == MAX_SIZE) {
        cout << "Stack is full." << endl;
        return; // If full, exit the function
    }

    // Check if the stack is empty
    if (pl.empty()) {
        cout << "Empty stack" << endl;
    } else {
        // Display and pop all elements in the stack
        while (!pl.empty()) {
            cout << pl.top() << endl;
            pl.pop();
        }
    }
}

int main() {
    stack<string> pl;

    // Push some elements onto the stack
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");

    // Display the stack
    display(pl);

    return 0;
}
