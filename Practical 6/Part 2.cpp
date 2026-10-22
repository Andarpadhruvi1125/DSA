#include <iostream>
#include <vector>
using namespace std;

vector<string> history;

void visitPage(string page) {
    history.push_back(page);
    cout << "Current page: " << page << endl;
}

void backPage() {
    if (history.size() <= 1) {
        cout << "Error: No previous page available." << endl;
        cout << "Current page: " << history[0] << endl;
        return;
    }

    history.pop_back();
    cout << "Current page: " << history.back() << endl;
}

int main() {
    string firstPage;

    cout << "Enter first page: ";
    cin >> firstPage;

    history.push_back(firstPage);

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice;
        string page;

        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;
            visitPage(page);
        }
        else if (choice == 2) {
            backPage();
        }
        else {
            cout << "Invalid operation." << endl;
        }
    }

    return 0;
}