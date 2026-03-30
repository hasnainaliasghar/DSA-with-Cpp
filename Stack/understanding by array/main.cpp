#include<iostream>
using namespace std;

class Stack{
    int top;
    int arr[5];

    public:
        Stack(){
            top = -1;
        }

        bool isfull(){
            return (top == 4);
        }

        bool isempty(){
            return (top==-1);
        }
        void push(int val){
            if(isfull()){
                cout<< "stack is full"<<endl;
                return;
            }
            arr[++top]  = val;
        }
        void pop(){
            if(isempty()){
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<"popped element"<<arr[top--];
        }
};

int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    cout<<endl;
    cout<<s1.isempty()<<endl;
    cout<<s1.isfull()<<endl;
    s1.pop();
}