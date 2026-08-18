#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;
    int bookID[n];
    cout << "Enter book IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> bookID[i];
    }
    cout << "Book IDs borrowed more than once are:\n";
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (bookID[i] == bookID[j])
            {
                count++;
            }
        }
        int printed = 0;
        for (int k = 0; k < i; k++)
        {
            if (bookID[i] == bookID[k])
            {
                printed = 1;
                break;
            }
        }

        if (count > 1 && printed == 0)
        {
            cout << bookID[i] << " ";
        }
    }
    return 0;
}