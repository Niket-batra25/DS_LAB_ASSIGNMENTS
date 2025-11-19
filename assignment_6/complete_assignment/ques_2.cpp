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

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head; 
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data;
    }
};


int main() {
    CircularLinkedList cll;

    cll.insert(20);
    cll.insert(100);
    cll.insert(40);
    cll.insert(80);
    cll.insert(60);

    cout << "Output: ";
    cll.display();

    return 0;
}
