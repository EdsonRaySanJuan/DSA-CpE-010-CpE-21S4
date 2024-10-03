// Queue FIFO(first in first out)
// Modify this code
#include <iostream>
#include <stack>
//#include <queue>

using namespace std;

int max_size = 4;

void fullStack(stack<string>);
void display (stack<string>);

int main(){
    
    stack<string>p1;
    cout<<"Push element into stack: "<<endl;
    // add item into stack
    p1.push("c++");
    p1.push("Java");
    p1.push("Python");
    //cout<<"Initial Stack: "<<endl;
    //display(p1);
    cout << '\n';
    cout<<"Final Stack: "<<endl;
    
    display(p1);
    
    fullStack(p1);
    return 0;
}

void fullStack(stack<string>p1){
    while(true){
        if(p1.size() < max_size){
                p1.pop();
                //break;
            }
        else {
            cout<<"Queue is FUll" << endl;
                
            }
    }
}
void display(stack<string>p1) {
    while(true){
        if(!p1.empty()){
            cout<<p1.top() << endl;
            p1.pop();
        }
        else {
            break;
        }
    }
}