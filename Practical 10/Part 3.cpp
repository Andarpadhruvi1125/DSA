#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student IDs:\n";

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);

        int index = h1;
        int j = 0;

        while (table[index] != -1 && j < 10) {
            j++;
            index = (h1 + j * h2) % 10;
        }

        if (j < 10)
            table[index] = id;
        else
            cout << "Table is full for ID " << id << endl;
    }

    cout << "\nFinal Student Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}