#include <iostream>
using namespace std;

int stack[100];
int top = -1;
int n;

void push(int value) {
    if (top == n - 1) {
        cout << "Error: Stack is full. Cannot place tray.\n";
        return;
    }

    top++;
    stack[top] = value;
    cout << "Current top tray: " << stack[top] << endl;
}

void pop() {
    if (top == -1) {
        cout << "Error: Stack is empty. Cannot take tray.\n";
        return;
    }

    cout << "Taken tray: " << stack[top] << endl;
    top--;

    if (top == -1)
        cout << "Stack is empty.\n";
    else
        cout << "Current top tray: " << stack[top] << endl;
}

int main() {
    cout << "Enter stack capacity: ";
    cin >> n;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice, value;

        cout << "\n1. Place tray";
        cout << "\n2. Take tray";
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else {
            cout << "Invalid operation.\n";
        }
    }

    return 0;
}