#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;

    Node(int p) {
        patient = p;
        next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void arrive(int patient) {
        Node* newNode = new Node(patient);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: Ward is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;

        if (front != nullptr)
            cout << "Front patient: " << front->patient << endl;
        else
            cout << "Front patient: None" << endl;
    }
};

int main() {
    int operations;
    cin >> operations;

    Queue q;

    for (int i = 0; i < operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "arrive") {
            int patient;
            cin >> patient;
            q.arrive(patient);
        }
        else if (operation == "attend") {
            q.attend();
        }
    }

    return 0;
}