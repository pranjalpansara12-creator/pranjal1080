#include<iostream>
using namespace std;

int main()
{
    int n;

    cout<<"enter the number of element:";
    cin>>n;

    int*arr = (int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
       cout<<"memory allocated failed!";
       return 0;
    }
    cout<< "Enter the elements:\n";
     for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }
    cout << "\nArray in reverse order:\n";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << *(arr + i) << " ";
    }
 free(arr);

    return 0;
}
