#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class list{
    Node* head ;
    Node* tail ;
public:
    list(){
        head=tail=NULL;
    }

    void puf(int val){
        Node* newNode =new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pub(int val){
        Node* newNode =new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void pof(){ 
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        ;
        delete temp;
    }

    void pob(){
        if(head==NULL){
           cout<<"ll is empty"<<endl;
           return; 
        }
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=head;
    }

    void inb(int val,int idx){
        Node* newNode =new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
            return;
        }else{
            int s=0;
            Node* temp=head;
            while(s!=idx){ 
                temp=temp->next;
                s++;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    void delb(int idx){
       if (head == NULL) {
        cout << "List is empty" << endl;
        return;
       }
       if (head == tail && idx == 0) {  // Only one node and deleting it
        delete head;
        head = tail = NULL;
        return;
        }
        if (idx == 0) {  // Delete front node
        pof();
        return;
        }
        int s=0;
        Node* temp=head;
        while(s!=idx-1 && temp->next != head){ 
           temp=temp->next;
           s++;
        }
        Node* b=temp->next;
        temp->next=b->next;
        delete b;
    }


    int search(int val){
        if(head==NULL){
            cout<<"ll is empty"<<endl;
            return -1;
        }else{
            int s=0;
            Node* temp=head;
            while(temp->data!=val){
                temp=temp->next;
                s++;
            }
            return s;
        }
    }

    void display(){
        if(head==NULL){
            cout<<"ll is empty"<<endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
     
};
int main(){
    list l;
    int choice, val, idx;

    do {
        cout << "\nCircular Linked List Menu-\n";
        cout << "1.Push Front (puf)\n";
        cout << "2. Push Back (pub)\n";
        cout << "3. Pop Front (pof)\n";
        cout << "4. Pop Back (pob)\n";
        cout << "5. Insert After Index (inb)\n";
        cout << "6. Delete At Index (delb)\n";
        cout << "7. Search Value\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push front: ";
            cin >> val;
            l.puf(val);
            cout << "Pushed " << val << " at front.\n";
            break;
        case 2:
            cout << "Enter value to push back: ";
            cin >> val;
            l.pub(val);
            cout << "Pushed " << val << " at back.\n";
            break;
        case 3:
            l.pof();
            cout << "Popped front element.\n";
            break;
        case 4:
            l.pob();
            cout << "Popped back element.\n";
            break;
        case 5:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter index after which to insert: ";
            cin >> idx;
            l.inb(val, idx);
            cout << "Inserted " << val << " after index " << idx << ".\n";
            break;
        case 6:
            cout << "Enter index to delete: ";
            cin >> idx;
            l.delb(idx);
            cout << "Deleted node at index " << idx << ".\n";
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            idx = l.search(val);
            if (idx == -1)
                cout << "Value " << val << " not found in list.\n";
            else
                cout << "Value " << val << " found at index " << idx << ".\n";
            break;
        case 8:
            l.display();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
