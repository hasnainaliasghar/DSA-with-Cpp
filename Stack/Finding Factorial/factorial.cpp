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

    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 1;
        }

        Node* temp = top;
        int data = temp -> data;
        top= top->next;
        temp -> next = nullptr;
        delete temp;
        return data;
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
    cout<<"Enter number: ";
    int num;
    cin>>num;
   
    for(int i = 1; i<= num ; i++){
        obj.push(i);
    }
   
    obj.printList();
   
    int fact = 1;
   
    for(int i = 0; i<num; i++){
        fact *= obj.pop();
    }
   
    cout<<"Factorial: "<<fact<<endl;
}
