
#include <iostream>
using namespace std;

#define SIZE 5

int st[SIZE];
int top = -1;

void push(int x) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
    } else {
        st[++top] = x;
        cout << "Inserted: " << x << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Deleted: " << st[top--] << endl;
    }
}

void peek() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << st[top] << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    for (int i = top; i >= 0; i--)
        cout << st[i] << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();

    return 0;
}
