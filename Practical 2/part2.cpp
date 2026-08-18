#include <iostream>
using namespace std;
int iterativeBinarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }
    else
    {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }
}

int main()
{
    int n;
    cout << "Enter number of book codes: ";
    cin >> n;
    int bookCode[n];
    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> bookCode[i];
    }

    int target;
    cout << "Enter target book code: ";
    cin >> target;

    int pos1 = iterativeBinarySearch(bookCode, n, target);

    if (pos1 != -1)
        cout << "Iterative Binary Search: Found at position " << pos1 << endl;
    else
        cout << "Iterative Binary Search: Not Found" << endl;

    int pos2 = recursiveBinarySearch(bookCode, 0, n - 1, target);
    if (pos2 != -1)
        cout << "Recursive Binary Search: Found at position " << pos2 << endl;
    else
        cout << "Recursive Binary Search: Not Found" << endl;
    return 0;
}