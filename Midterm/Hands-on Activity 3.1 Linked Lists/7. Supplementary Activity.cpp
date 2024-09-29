#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string s) : song(s), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    Node* current;

public:
    CircularLinkedList() : head(nullptr), current(nullptr) {}

    // Create the playlist with multiple songs
    void createPlaylist(const vector<string>& songs) {
        if (songs.empty()) {
            cout << "No songs to add to the playlist." << endl;
            return;
        }

        head = new Node(songs[0]);
        current = head;
        Node* last = head;

        for (size_t i = 1; i < songs.size(); ++i) {
            last->next = new Node(songs[i]);
            last = last->next;
        }

        last->next = head; // Make it circular
        cout << "Playlist created successfully." << endl;
    }

    // Add a new song to the playlist
    void addSong(const string& song) {
        Node* newNode = new Node(song);
        if (!head) {
            head = newNode;
            newNode->next = newNode;
            current = newNode;
            cout << "Added '" << song << "' as the first song in the playlist." << endl;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
        cout << "Added '" << song << "' to the playlist." << endl;
    }

    // Remove a song from the playlist
    void removeSong(const string& song) {
        if (!head) {
            cout << "Playlist is empty. No songs to remove." << endl;
            return;
        }

        Node* currentNode = head;
        Node* prev = nullptr;
        bool found = false;

        do {
            if (currentNode->song == song) {
                found = true;
                break;
            }
            prev = currentNode;
            currentNode = currentNode->next;
        } while (currentNode != head);

        if (!found) {
            cout << "Song '" << song << "' not found in the playlist." << endl;
            return;
        }

        if (currentNode == head) {
            if (head->next == head) {
                // Only one node in the list
                delete head;
                head = nullptr;
                current = nullptr;
            } else {
                // Find the last node to update its next pointer
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = head->next;
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            prev->next = currentNode->next;
            delete currentNode;
        }

        cout << "Removed '" << song << "' from the playlist." << endl;
    }

    // Play all songs once
    void playAllSongs() const {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Playing all songs:" << endl;
        Node* temp = head;
        do {
            cout << "Playing: " << temp->song << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Move to the next song
    void nextSong() {
        if (!current) {
            cout << "Playlist is empty." << endl;
            return;
        }

        current = current->next;
        cout << "Next song: " << current->song << endl;
    }

    // Move to the previous song
    void previousSong() {
        if (!head || !current) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Find the node that points to current
        while (temp->next != current && temp->next != head) {
            temp = temp->next;
        }

        if (temp->next == head && head != current) {
            // Wrap around to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
        }

        current = temp;
        cout << "Previous song: " << current->song << endl;
    }

    // Display all songs in the playlist
    void displayPlaylist() const {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Current Playlist:" << endl;
        Node* temp = head;
        do {
            cout << temp->song;
            temp = temp->next;
            if (temp != head)
                cout << " -> ";
        } while (temp != head);
        cout << endl;
    }

    // Destructor to clean up memory
    ~CircularLinkedList() {
        if (!head) return;

        Node* temp = head->next;
        while (temp != head) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete head;
    }
};

int main() {
    CircularLinkedList playlist;
    int choice;

    while (true) {
        cout << "\n--- Music Playlist Menu ---" << endl;
        cout << "1. Create Playlist" << endl;
        cout << "2. Add Song" << endl;
        cout << "3. Remove Song" << endl;
        cout << "4. Play All Songs" << endl;
        cout << "5. Next Song" << endl;
        cout << "6. Previous Song" << endl;
        cout << "7. Display Playlist" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the integer input

        switch (choice) {
            case 1: {
                cout << "Enter songs separated by commas: ";
                string input;
                getline(cin, input);
                vector<string> songs;
                size_t pos = 0;
                while ((pos = input.find(',')) != string::npos) {
                    string song = input.substr(0, pos);
                    // Trim leading and trailing spaces
                    size_t start = song.find_first_not_of(" \t");
                    size_t end = song.find_last_not_of(" \t");
                    if (start != string::npos && end != string::npos)
                        song = song.substr(start, end - start + 1);
                    songs.push_back(song);
                    input.erase(0, pos + 1);
                }
                // Add the last song
                string lastSong = input;
                size_t start = lastSong.find_first_not_of(" \t");
                size_t end = lastSong.find_last_not_of(" \t");
                if (start != string::npos && end != string::npos)
                    lastSong = lastSong.substr(start, end - start + 1);
                if (!lastSong.empty())
                    songs.push_back(lastSong);
                playlist.createPlaylist(songs);
                break;
            }
            case 2: {
                cout << "Enter the song to add: ";
                string song;
                getline(cin, song);
                // Trim leading and trailing spaces
                size_t start = song.find_first_not_of(" \t");
                size_t end = song.find_last_not_of(" \t");
                if (start != string::npos && end != string::npos)
                    song = song.substr(start, end - start + 1);
                playlist.addSong(song);
                break;
            }
            case 3: {
                cout << "Enter the song to remove: ";
                string song;
                getline(cin, song);
                // Trim leading and trailing spaces
                size_t start = song.find_first_not_of(" \t");
                size_t end = song.find_last_not_of(" \t");
                if (start != string::npos && end != string::npos)
                    song = song.substr(start, end - start + 1);
                playlist.removeSong(song);
                break;
            }
            case 4:
                playlist.playAllSongs();
                break;
            case 5:
                playlist.nextSong();
                break;
            case 6:
                playlist.previousSong();
                break;
            case 7:
                playlist.displayPlaylist();
                break;
            case 8:
                cout << "Exiting the playlist manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
