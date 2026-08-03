#include <iostream>
using namespace std;

void callByValue(int a)
{
    a = a + 10;
    cout << "Value inside callByValue() = " << a << endl;
}

void callByReference(int *b)
{
    *b = *b + 10;
    cout << "Value inside callByReference() = " << *b << endl;
}

int main()
{

    int a = 50;

    cout << "----- Call by Value -----" << endl;
    cout << "Original value of a = " << a << endl;

    callByValue(a);

    cout << "Value of a after function call = " << a << endl;



    int b = 50;

    cout << "\n----- Call by Reference -----" << endl;
    cout << "Original value of b = " << b << endl;

    callByReference(&b);

    cout << "Value of b after function call = " << b << endl;

    return 0;
}
