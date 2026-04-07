#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Stack {
    private:
        int arr[MAX];
        int top;

    public:
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            if(top == -1)
                return true;
            return false;
        }

        bool isFull(){
            if(top == MAX-1)  
                return true;
            return false;
        }

        void push(int val){
            if(isFull()){
                cout<<"Stack is Full"<<endl;
                return;
            }
            arr[++top] = val;
           
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return;
            }
            arr[top--];
        }

        void printStack(){
            for(int i = 0; i<= top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};



int main(){
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
   
    stack.printStack();
    stack.pop();
    stack.printStack();
    return 0;
}