#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> q;
    
    
    if (q.empty()){
        cout <<"Underflow." << endl;
    }
    
    // Insertion
    int value[] = {10, 24, 28, 32, 30};
    for(int i = 0; i < 5; i++){
        q.push(value[i]);
        cout<< value[i] << " has been inserted successfully." << endl;
        
    }

    queue<int> tempq = q;
    while(!tempq.empty()){
        cout << tempq.front() << " ";
        tempq.pop();
        }
        
    cout << endl;
    
    // Deletion
    while (!q.empty()){
        cout << q.front() << " has been deleted" << endl;
        q.pop();
    }
    
    return 0;
    
    
}