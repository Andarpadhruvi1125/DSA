#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token) {
        if (count == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        count++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        front = (front + 1) % capacity;
        count--;

        if (count > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Front token: None" << endl;
    }
};

int main() {
    int n, operations;
    cin >> n;
    cin >> operations;

    Queue q(n);

    for (int i = 0; i < operations; i++) {
        string operation;
        cin >> operation;

        if (operation == "join") {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (operation == "serve") {
            q.serve();
        }
    }

    return 0;
}