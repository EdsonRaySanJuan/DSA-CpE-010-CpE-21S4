#include <iostream> 
#include <queue>    
using namespace std; 


void display(queue<string> pl) {
    while (!pl.empty()) {
        cout << pl.front() << endl;
        pl.pop();
    }
}

int main() {
    queue<string> pl; 
    int maxSize = 3; // maximum size of the queue

    // Array of programming languages to add to the queue (java script)
    string proglang[] = {"C++", "Java", "Python", "JavaScript"}; 

    // Adding elements from the array to the queue
    for (int i = 0; i < 4; ++i) { // Loop through the array of languages
        
        if (pl.size() < maxSize) {
            pl.push(proglang[i]); // Add the current language to the queue
            cout << proglang[i] << " added to the queue." << endl;
        } else {
            // If the queue is full, notify the user
            cout << "Queue is already full. Cannot add " << proglang[i] << "." << endl;
        }
    }

    // Display the current elements in the queue
    cout << "Elements in the queue: " << endl;
    display(pl); // Call the display function to print and empty the queue

    return 0; 
}