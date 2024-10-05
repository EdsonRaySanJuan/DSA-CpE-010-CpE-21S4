#include <iostream>
#include <stack>

using namespace std;

// Function to check if the stack is balanced
bool isBalanced(const char* input, int length) {
    // Reverse the input string
    char tempInput[length + 1];
    int i = 0;
    while (i < length) {
        tempInput[i] = input[length - i - 1];
        i++;
    }
    tempInput[length] = '\0';

    // Create a stack to store the opening symbols
    stack<char> stack;

    // While(end of input is not reached)
    int j = 0;
    while (tempInput[j] != '\0') {
        // a) If the character read is not a symbol to be balanced, ignore it. 
        // b) If the character is an opening symbol, push it onto the stack. 
        if (tempInput[j] == '(' || tempInput[j] == '[' || tempInput[j] == '{') {
            stack.push(tempInput[j]);
        }
        // c) If it is a closing symbol
        else if (tempInput[j] == ')' || tempInput[j] == ']' || tempInput[j] == '}') {
            //     i) Report an error if the stack is empty. 
            if (stack.empty()) {
                cout << "Error: Unbalanced symbol " << tempInput[j] << endl;
                return false;
            }
            //     ii) Otherwise, pop the stack. 
            char topSymbol = stack.top();
            stack.pop();
            if ((tempInput[j] == ')' && topSymbol != '(') ||
                (tempInput[j] == ']' && topSymbol != '[') ||
                (tempInput[j] == '}' && topSymbol != '{')) {
                // Print an error message if the symbols do not match
                cout << "Error: Unbalanced symbol " << tempInput[j] << endl;
                return false;
            }
        }
        // Increment the index to move to the next character in the input string
        j++;
    }
    // d) If the symbol popped is not the corresponding opening symbol, report an error. 
    if (!stack.empty()) {
        cout << "Error: Unbalanced symbol. Stack is not empty" << endl;
        return false;
    } else {
        cout << "Symbols are balanced" << endl;
        return true;
    }
}

int main() {
    stack<char> st;
    st.push('(');
    st.push('{');
    st.push('[');
    st.push(']');
    st.push('}');
    st.push(')');
    char input[20]; 
    int i = 0;
    while (!st.empty()) {
        input[i++] = st.top();
        st.pop();
    }
    input[i] = '\0'; 

    isBalanced(input, i);
    return 0;
}