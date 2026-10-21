
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

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* p = head;
    while (p->next != head)
        p = p->next;

    n->next = head;
    p->next = n;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* p = head;
    while (p->next != head)
        p = p->next;

    p->next = n;
    n->next = head;
}

void insertAfter(int key, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* p = head;

    do {
        if (p->data == key) {
            Node* n = new Node;
            n->data = x;
            n->next = p->next;
            p->next = n;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "Node not found\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* p = head;
    do {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != head);

    cout << "(back to head)\n";
}

int main() {
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(40);
    insertAfter(20, 30);

    cout << "Circular Linked List: ";
    display();

    return 0;
}
