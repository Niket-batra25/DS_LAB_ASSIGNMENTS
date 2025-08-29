#include <iostream>
using namespace std;

#define MAX 5

class stack{
    int arr[MAX];
    int top;
    
public:
    stack(){
        top=-1;
    }
    
    bool isempty(){
        return top==-1;
    }
    
    bool isfull(){
        return top==MAX-1;
    }
    
    void push(int x){
        if (isfull()){
            cout<<"stack overflow! cannot push "<<x<<endl;
        }else{
            arr[++top]=x;
            cout<<x<<" is pushed into stack"<<endl;
        }
    }
    
    void pop(){
        if(isempty()){
            cout<<"stack is empty,no top element."<<endl;
        }else{
            cout<<"top element: "<<arr[top--]<<" popped from stack."<<endl;
        }
    }
    
    void peek(){
        if (isempty()){
            cout<<"stack is empty."<<endl;
        }else{
            cout<<"top element: "<<arr[top]<<endl;
        }
    }
    
    void display(){
        if (isempty()){
            cout<<"stack is empty."<<endl;
        }else{
            cout<<"stack elements: ";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    stack s;
    int choice,value;
    
    do{
        cout<<"\nSTACK MENU-->\n";
        cout<<"1. push\n2. pop\n3. peek\n4. isempty\n5. isfull\n6. display\n0. exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch (choice){
        case 1:
            cout<<"enter value to push";
            cin>>value;
            s.push(value);
            break;
         
        case 2:
            s.pop();
            break;
            
        case 3:
            s.peek();
            break;
            
        case 4:
            if (s.isfull()){
                cout<<"stack is full."<<endl;
            }else{
                cout<<"stack is not full."<<endl;
            }
        
         case 5:
            if (s.isfull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;

        case 6:
            s.display();
            break;

        case 0:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;    
        }
        
    }while (choice != 0);
    
    return 0;
}