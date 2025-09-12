#include<iostream>
using namespace std;

struct node{
    int data;
    Node* next;
}

Node* head = NULL;

void in_at_big(int val){
    node* newNode =new Node();
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}

void in_at_end(int val){
    Node* newNode =new Node();
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next
        }
        temp->next=newNode;
    }
}

void in_in_bet(int val, int beforeVal, int afterVal) {
        Node* temp=head;
        Node* prev=nullptr;
        while (temp) {
            if (temp->data==beforeVal) {
                Node* newNode=new Node{val, temp};
                if (prev) prev->next=newNode;
                else head = newNode;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        temp = head;
        while (temp) {
            if (temp->data==afterVal) {
                Node* newNode=new Node{val, temp->next};
                temp->next=newNode;
                return;
            }
            temp=temp->next;
        }
        cout <<"neither "<<beforeVal<<"nor "<<afterVal<< " found in the list"<<endl;
}
    
void del_from_beg() {
        if (!head) {
            cout<<"list is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
}
    
void del_from_end() {
        if (!head) {
            cout<<"list is empty"<<endl;
            return;
        }
        if (!head->next) {
            delete head;
            head=nullptr;
            return;
        }
        Node* temp=head;
        while (temp->next && temp->next->next) temp=temp->next;
        delete temp->next;
        temp->next=nullptr;
}

void del_speci(int val) {
    if (!head) {
        cout<<"list is empty"<<endl;
        return;
    }
    if (head->data==val) {
        Node* temp=head;
        head=head->next;
        delete temp;
        cout<<"node with value "<<val<<" deleted from the list"<<endl;
        return;
    }
    Node* temp=head;
    Node* prev=nullptr;
    while (temp && temp->data!=val) {
        prev=temp;
        temp=temp->next;
    }
    if (!temp) {
        cout<<"value "<<val<<" not found in the list"<<endl;
        return;
    }
    prev->next=temp->next;
    delete temp;
    cout<<"Node with value "<<val<<" deleted from the list"<<endl;
}

 void sea_from_end(int val) {
        int length=0;
        Node* temp=head;
        while (temp) {
            length++;
            temp=temp->next;
        }
        temp=head;
        int pos=1;
        bool found=false;
        while (temp) {
            if (temp->data==val) {
                cout<<"node with value "<<val<<" found at position "<<pos<<" from beginnin."<,endl;
                cout< "position from end: "<<(length - pos + 1)<<endl;
                found = true;
                break;
            }
            pos++;
            temp=temp->next;
        }
        if (!found)
            cout<<"Value "<<val<<" not found in the list"<<endl;
    }

int main{
    
}