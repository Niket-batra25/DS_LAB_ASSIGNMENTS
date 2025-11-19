#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class list {
    Node* head;
    Node* tail;

public:
    list() {
        head = tail = NULL;
    }

    void puf(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void pub(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pof() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        if (head == tail) {    
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void pob() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) {     
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void inb(int val, int idx) {
        if (head == NULL) {
            cout << "List empty, inserting at front\n";
            puf(val);
            return;
        }

        Node* temp = head;
        int pos = 0;

        while (pos < idx && temp->next != NULL) {
            temp = temp->next;
            pos++;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;

        if (temp == tail)
            tail = newNode;
    }

    void delb(int idx) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (idx == 0) {
            pof();
            return;
        }

        Node* temp = head;
        int pos = 0;

        while (pos < idx && temp != NULL) {
            temp = temp->next;
            pos++;
        }

        if (temp == NULL) {
            cout << "Index out of range\n";
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        temp->prev->next = temp->next;

        if (temp == tail)
            tail = tail->prev;

        delete temp;
    }

    int search(int val) {
        Node* temp = head;
        int idx = 0;

        while (temp != NULL) {
            if (temp->data == val)
                return idx;
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    list l;
    int choice, val, idx;

    do {
        cout << "\nDoubly Linked List Menu-\n";
        cout << "1. Push Front\n";
        cout << "2. Push Back\n";
        cout << "3. Pop Front\n";
        cout << "4. Pop Back\n";
        cout << "5. Insert After Index\n";
        cout << "6. Delete At Index\n";
        cout << "7. Search Value\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            l.puf(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            l.pub(val);
            break;

        case 3:
            l.pof();
            break;

        case 4:
            l.pob();
            break;

        case 5:
            cout << "Value: "; cin >> val;
            cout << "Index: "; cin >> idx;
            l.inb(val, idx);
            break;

        case 6:
            cout << "Index: "; cin >> idx;
            l.delb(idx);
            break;

        case 7:
            cout << "Search value: ";
            cin >> val;
            idx = l.search(val);
            if (idx == -1)
                cout << "Not found\n";
            else
                cout << "Found at index " << idx << endl;
            break;

        case 8:
            l.display();
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    return 0;
}
