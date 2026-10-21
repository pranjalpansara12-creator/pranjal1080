
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = n;
}

void insertAfter(int key, int x) {
    Node* p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* n = new Node;
    n->data = x;
    n->next = p->next;
    p->next = n;
}

void display() {
    Node* p = head;

    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }

    cout << "NULL\n";
}

int main() {
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(40);
    insertAfter(20, 30);

    cout << "Linked List: ";
    display();

    return 0;
}
