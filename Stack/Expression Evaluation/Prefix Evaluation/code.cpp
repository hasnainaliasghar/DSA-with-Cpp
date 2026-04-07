#include<iostream>
#include<math.h>
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

int prefixEvaluation(string operation){
    Stack s;

    for(int i = operation.length()-1; i>=0 ; i--){
        
        if(operation[i] >= '0' && operation[i] <= '9'){
            s.push(operation[i]-'0');
        } else {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (operation[i])
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

    return s.top();

}

int main(){
    int answer = prefixEvaluation("-+7*45+20");
    cout<<answer;
    return 0;
}