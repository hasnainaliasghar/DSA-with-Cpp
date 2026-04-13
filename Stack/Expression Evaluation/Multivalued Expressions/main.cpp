#include<iostream>
#include<math.h>
#include<sstream>
#include<string>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Stack{
    Node* head;

    public:

    Stack(){
        head = nullptr;
    }

    void push(int val){
        Node* newNode = new Node(val);

        if (head == nullptr){
            head = newNode;
            return;
        }

        newNode -> next = head;
        head = newNode;
    }

    void pop(){
        if(head == nullptr){
            return;
        }

        Node* temp = head;
        head = head -> next;

        temp -> next = nullptr;
        delete temp;
    }

    int top(){
        if(head == nullptr){
            return 0;
        }
        return int(head -> data);
    }
};

int prefixevaluation(string expression){
    Stack s;
    stringstream ss(expression);
    string token;

    while(ss >> token){

        if(isdigit(stoi(token))){
            s.push(stoi(token));
        } else {
             int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (char(token[0]))
            {
            case '+':
                s.push(op1+op2);
                break;
            case '-':
                s.push(op1-op2);
                break;
            case '*':
                s.push(op1*op2);
                break;
            case '/':
                s.push(op1/op2);
                break;
            case '^':
                s.push(pow(op1,op2));
                break; 
            default:
                break;
        }
    }
    
}
}

int main(){
    cout<<prefixevaluation("+ 23 45");
}