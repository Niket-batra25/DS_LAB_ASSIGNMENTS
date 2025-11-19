#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next != head)
            temp = temp->next;

        temp->next = newNode;
    }

    bool isCircular() {
        if (head == NULL) return true;  

        Node* temp = head->next;

        while (temp != NULL && temp != head) {
            temp = temp->next;
        }

        return (temp == head);
    }
};

int main() {
    LinkedList ll;

    ll.insert(2);
    ll.insert(4);
    ll.insert(6);
    ll.insert(7);
    ll.insert(5);

    Node* temp = ll.head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = ll.head;   

    if (ll.isCircular())
        cout << "True";
    else
        cout << "False";

    return 0;
}
