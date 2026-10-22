#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(string n) : name(n), next(nullptr) {}
};

Node* head = nullptr;

void joinCircle(string name, int pos) {
    Node* newNode = new Node(name);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    if (pos == 1) {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    } else {
        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr->next != head; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void leaveCircle(string name) {
    if (head == nullptr) {
        cout << "\n[Circle is empty!]\n";
        return;
    }
    if (head->name == name && head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;
    do {
        if (curr->name == name) break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->name != name) {
        cout << "\n[Student \"" << name << "\" not found!]\n";
        return;
    }

    if (curr == head) {
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        head = head->next;
        tail->next = head;
    } else {
        prev->next = curr->next;
    }
    delete curr;
}

void displayCircle() {
    cout << "\n--- Singly Circular Circle ---\n";
    if (head == nullptr) {
        cout << "(empty)\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to " << head->name << ")\n";
}

int main() {
    int choice, pos;
    string name;

    while (true) {
        cout << "\n=================================\n";
        cout << "   SINGLY CIRCULAR PASSING GAME  \n";
        cout << "1. Join Circle\n";
        cout << "2. Leave Circle\n";
        cout << "3. Display Circle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter position to join (1 for front): ";
            cin >> pos;
            joinCircle(name, pos);
            displayCircle();
        }
        else if (choice == 2) {
            cout << "Enter student name to leave: ";
            getline(cin, name);
            leaveCircle(name);
            displayCircle();
        }
        else if (choice == 3) {
            displayCircle();
        }
        else if (choice == 4) {
            cout << "Exiting game. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}