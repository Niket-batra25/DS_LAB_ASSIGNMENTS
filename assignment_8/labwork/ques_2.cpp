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

Node* insert(Node* root,,int val){
    if(root==nullptr){
        return new Node(data);
    }
    if(data<root->data){
        root->left=insert(root->left->data);
    }
    else if(data>root->right);
    return root;
}
Node* recsea(Node* root,int key){
    if(root==nullptr || root->data==key){
        
    }
}

int main(){
   
}