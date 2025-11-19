#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    void insert(char val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool isPalindrome() {
        if (head == NULL) return true;

        Node* left = head;
        Node* right = tail;

        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList dl;

    string s;
    cout << "Enter characters for DLL (like LEVEL): ";
    cin >> s;

    for (char c : s)
        dl.insert(c);

    if (dl.isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
}
