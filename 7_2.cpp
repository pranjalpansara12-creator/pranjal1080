
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

void deleteFirst() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* p = head;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    delete p;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* p = head;
    while (p->next->next != head)
        p = p->next;

    delete p->next;
    p->next = head;
}

void deleteAfter(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* p = head;

    do {
        if (p->data == key) {
            Node* temp = p->next;

            if (temp == head) {
                cout << "Cannot delete head using this operation\n";
                return;
            }

            p->next = temp->next;
            delete temp;
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
