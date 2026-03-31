#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Stack{
    Node* top;

    public:
    Stack(){
        top = nullptr;
    }

    bool empty(){
        return (top == nullptr);
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(empty()){
            top = newNode;
            return;
        }
        
        newNode -> next = top;
        top = newNode;
    }

    int pop(){
        if(empty()){
            cout<<"Stack is empty"<<endl;
        }

        Node* temp = top;
        top = top -> next;
        int data = temp -> data;
        temp -> next = nullptr;
        delete temp;

        return data;
        
    }

    void printList(){
        Node* temp = top;
        cout<<"Stack Elements: ";
        while(temp != nullptr){
            cout<<temp -> data << " ";
            temp = temp -> next;
        }

        cout<<endl;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(25);
    s.push(5);
    s.push(40);
    s.push(15);

    s.printList();
    int max = 0, sum = 0;
    while(!s.empty()){
        int val = s.pop();
        if(val > max) max = val;
        sum += val;
    }

    cout<<"Maximum Value: "<<max<<endl;
    cout<<"Sum of Elements: "<<sum<<endl;

    return 0;
}