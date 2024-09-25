// Queue FIFO(first in first out)
// Modify this code
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int max_size = 4;

void display (queue<string>);

int main(){
    queue<string>p1;
    cout<<"Push element into stack: "<<endl;
    // add item into stack
    p1.push("c++");
    p1.push("Java");
    p1.push("Python");
    cout<<"Initial Stack: "<<endl;
    display(p1);
    cout<<"Final Stack: "<<endl;
    p1.pop();
    display(p1);
 
    return 0;
}

void fullStack(queue<string>p1){
    if(p1.size < max_size){
            p1.pop();
        }
        else {
            cout<<"Queue is FUll" << endl;
            break;
        }
}
void display(queue<string>p1) {
    while(true){
        if(!p1.empty()){
            cout<<p1.front() << endl;
            p1.pop();
        }
        else {
            break;
        }
    }
}