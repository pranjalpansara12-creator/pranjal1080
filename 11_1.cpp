
#include <iostream>
using namespace std;

int main() {
    int a[100], n, key;
    int low, high, mid;
    bool found = false;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted elements in ascending order: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            cout << "Element found at position "
                 << mid + 1 << endl;
            found = true;
            break;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found)
        cout << "Element not found";

    return 0;
}
