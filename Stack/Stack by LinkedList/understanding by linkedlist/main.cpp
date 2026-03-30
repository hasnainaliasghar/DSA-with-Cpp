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

class stack{
    private:
    Node* top;
    public:
    stack(){
        top = nullptr;
    }

    bool isEmpty(){
        return (top == nullptr);
    }

    void push(int val){
        Node* newNode = new Node(val);
        newNode -> next = top;
        top = newNode;
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return;
        }

        Node* temp = top;
        top= top->next;
        temp -> next = nullptr;
        delete temp;
    }
    void printList(){
        Node* temp = top;
        while(temp != nullptr){
            cout<<temp -> data << " ";
            temp = temp -> next;
        }

        cout<<endl;
    }
};

int main(){
    stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);

    obj.printList();

    obj.pop();
    obj.printList();
}