#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertInBetween(int val, int beforeVal, int afterVal) {
    Node* temp = head;
    Node* prev = nullptr;

   
    while (temp) {
        if (temp->data == beforeVal) {
            Node* newNode = new Node{val, temp};
            if (prev) prev->next = newNode;
            else head = newNode;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

   
    temp = head;
    while (temp) {
        if (temp->data == afterVal) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Neither " << beforeVal << " nor " << afterVal << " found in the list" << endl;
}


void deleteFromBeginning() {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}


void deleteFromEnd() {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}


void deleteSpecific(int val) {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << val << " deleted" << endl;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Value " << val << " not found" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Node with value " << val << " deleted" << endl;
}


void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == val) {
            cout << "Node with value " << val << " found at position " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    }
    cout << "Value " << val << " not found" << endl;
}


void displayList() {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {
    int choice, val, beforeVal, afterVal;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific node\n";
        cout << "7. Search node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value before which to insert (or -1 to skip): ";
            cin >> beforeVal;
            cout << "Enter value after which to insert (or -1 to skip): ";
            cin >> afterVal;
            insertInBetween(val, beforeVal, afterVal);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteSpecific(val);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 8:
            displayList();
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
