
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void deleteFirst() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* p = head;
    head = head->next;
    delete p;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* p = head;
    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

void deleteAfter(int key) {
    Node* p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL || p->next == NULL) {
        cout << "Node or next node not found\n";
        return;
    }

    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
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
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "Original List: ";
    display();

    deleteFirst();
    cout << "After deleting first: ";
    display();

    deleteLast();
    cout << "After deleting last: ";
    display();

    deleteAfter(20);
    cout << "After deleting node after 20: ";
    display();

    return 0;
}
