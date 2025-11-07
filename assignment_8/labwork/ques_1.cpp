#include<iostream>
using namespace std;

struct Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* newNode(int val){
    return new Node(val);
}

void pre_ot(Node* node){
    if(node==nullptr) return;
    cout<<node->data<<" ";
    pre_ot(node->left);
    pre_ot(node->right);
}

void in_ot(Node* node){
    if(node==nullptr) return;
    in_ot(node->left);
    cout<<node->data<<" ";
    in_ot(node->right);
}

void post_ot(Node* node){
    if(node==nullptr) return;
    post_ot(node->left);
    post_ot(node->right);
    cout<<node->data<<" ";
}

int main(){
    Node* root=newNode(3);
    root->left=newNode(9);
    root->right=newNode(20);
    root->right->left=newNode(15);
    root->right->left=newNode(7);
    pre_ot(root);
    in_ot(root);
    post_ot(root);
}