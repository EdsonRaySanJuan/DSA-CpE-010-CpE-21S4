#include <iostream>
#include <string>
using namespace std;

class Job {
public:
    int jobID;               
    string userName;        
    int numberOfPages;     

    // Constructor to initialize the Job attributes
    Job(int id, string name, int pages) : jobID(id), userName(name), numberOfPages(pages) {}
};

class Node {
public:
    Job* job;              
    Node* next;            
    Node(Job* j) : job(j), next(nullptr) {} // Constructor to initialize the Node
};

class Printer {
private:
    Node* front;            
    Node* back;             

public:
    Printer() : front(nullptr), back(nullptr) {} // Constructor to initialize front and back

    // Method to add a new job to the queue
    void addJob(Job* newJob) {
        Node* newNode = new Node(newJob);
        if (back) { // If there are existing jobs
            back->next = newNode; // Link the new job at the back
        } else { // If queue is empty
            front = newNode; // The new job is now the front
        }
        back = newNode; // Update the back to the new job
        cout << "Job ID: " << newJob->jobID << " submitted by " << newJob->userName << " for " 
             << newJob->numberOfPages << " pages." << endl;
    }

    void processJobs() {
        while (front) {
            Job* currentJob = front->job; // Get the job at the front
            cout << "Processing Job ID: " << currentJob->jobID << " for " 
                 << currentJob->userName << " (" << currentJob->numberOfPages << " pages)." << endl;

            // Simulating job processing time
            for (int i = 0; i < currentJob->numberOfPages; i++) {
                cout << "Printing page " << (i + 1) << " of Job ID: " << currentJob->jobID << endl;
            }

            // Remove the job from the queue
            Node* temp = front; 
            front = front->next; // Move front pointer to the next job
            delete temp; // Free the memory
        }
        back = nullptr; // Reset back when all jobs are processed
    }
};

int main() {
    Printer printer;

    printer.addJob(new Job(1, "Alice", 3)); // Job 1 from Alice for 3 pages
    printer.addJob(new Job(2, "Bob", 2));   // Job 2 from Bob for 2 pages
    printer.addJob(new Job(3, "Charlie", 1)); // Job 3 from Charlie for 1 page
    printer.addJob(new Job(4, "Diana", 4)); // Job 4 from Diana for 4 pages

    printer.processJobs();

    return 0; 
}
