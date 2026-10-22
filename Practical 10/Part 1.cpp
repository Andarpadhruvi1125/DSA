#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle registration numbers:\n";

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;

        int index = number % 10;
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % 10;

            if (index == start) {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if (table[index] == -1)
            table[index] = number;
    }

    cout << "\nFinal Parking Table:\n";

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