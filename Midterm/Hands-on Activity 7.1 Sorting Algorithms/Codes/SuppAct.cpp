#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void displayVoteResults(int arr[], int n) {
    int count[5] = {0};
    
    // Count the votes for each candidate
    for (int i = 0; i < n; i++) {
        count[arr[i] - 1]++;
    }
    
    cout << "Vote counts for each candidate:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << (i + 1) << ": " << count[i] << " votes" << endl;
    }
    
    int maxVotes = count[0];
    int winner = 1;
    for (int i = 1; i < 5; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            winner = i + 1;
        }
    }
    
    cout << "\nThe winning candidate is Candidate " << winner << " with " << maxVotes << " votes." << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    const int size = 100;
    int votes[size];

    // Generate random votes between 1 and 5
    for (int i = 0; i < size; i++) {
        votes[i] = rand() % 5 + 1;
    }

    cout << "Randomly generated votes:" << endl;
    for (int i = 0; i < size; i++) {
        cout << votes[i] << " ";
        if ((i + 1) % 20 == 0)
            cout << endl;
    }
    cout << endl;

    // Sort votes and display results
    selectionSort(votes, size);
    displayVoteResults(votes, size);

    return 0;
}

