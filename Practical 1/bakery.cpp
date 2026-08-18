#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int h;
    cout << "Enter number of rotations: ";
    cin >> h;

    h = h % n; 

    for(int j = 0; j < h; j++)
    {
        int a = arr[0];

        for(int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = a;
    }

    cout << "Array after rotation:\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}