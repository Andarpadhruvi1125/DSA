#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
    Node(string s) : song(s), prev(nullptr), next(nullptr) {}
};

Node* head = nullptr;

void addBeginning(string song) {
    Node* newNode = new Node(song);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addEnd(string song) {
    Node* newNode = new Node(song);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(string target, string song) {
    Node* temp = head;
    while (temp != nullptr && temp->song != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "\n[Error: Song \"" << target << "\" was not found in the playlist!]\n";
        return;
    }

    Node* newNode = new Node(song);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void removeFirst() {
    if (head == nullptr) {
        cout << "\n[Playlist is empty. Nothing to remove!]\n";
        return;
    }
    Node* temp = head;
    cout << "\nRemoving: " << head->song << endl;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void display() {
    Node* temp = head;
    int count = 0;
    cout << "\n--- Current Playlist ---\n";
    if (temp == nullptr) {
        cout << "(empty)\n";
        cout << "Total songs: 0\n";
        return;
    }
    while (temp != nullptr) {
        cout << "[" << temp->song << "] ";
        count++;
        temp = temp->next;
    }
    cout << "\nTotal songs: " << count << "\n";

}
int main() {
    int choice;
    string songName, targetSong;

    while (true) {
        cout << "      MUSIC PLAYER MENU          \n";
        cout << "=================================\n";
        cout << "1. Add song to Beginning\n";
        cout << "2. Add song to End\n";
        cout << "3. Insert song After a specific song\n";
        cout << "4. Remove First song\n";
        cout << "5. Display Playlist and Total Count\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            cout << "Enter song name to add at beginning: ";
            getline(cin, songName);
            addBeginning(songName);
            display();
        }
        else if (choice == 2) {
            cout << "Enter song name to add at end: ";
            getline(cin, songName);
            addEnd(songName);
            display();
        }
        else if (choice == 3) {
            cout << "Enter the song name currently playing (target song): ";
            getline(cin, targetSong);
            cout << "Enter the new song name to insert after \"" << targetSong << "\": ";
            getline(cin, songName);
            insertAfter(targetSong, songName);
            display();
        }
        else if (choice == 4) {
            removeFirst();
            display();
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            cout << "Exiting Music Player.\n";
            break;
        }
        else {
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}