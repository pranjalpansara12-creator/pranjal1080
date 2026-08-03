#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n, i;


    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    cout << "\nArray elements are: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    int value, pos;
    cout << "\n\nEnter position to insert (starting from 1): ";
    cin >> pos;

    cout << "Enter value to insert: ";
    cin >> value;


    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Array after insertion: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    cout << "\n\nEnter position to delete: ";
    cin >> pos;


    for (i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Array after deletion: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    int key;
    bool found = false;

    cout << "\n\nEnter element to search: ";
    cin >> key;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "Element not found.";
    }

    return 0;
}
