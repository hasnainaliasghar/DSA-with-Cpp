#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Stack {
    private:
        string arr[MAX];
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

        void push(string word){
            if(isFull()){
                cout<<"Stack is Full"<<endl;
                return;
            }
            arr[++top] = word;
            
            cout<< "Word /"<<word<<"/ pushed successfully"<<endl;
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

void menu(){
    cout<<"Menu"<<endl;
    cout<<"1.Push word\n2.Undo word\n3.Display Current Text\n4.Exit Program"<<endl;
}

int main(){
    Stack stack;
    bool isOn = true;

    menu();

    while(isOn){
        
        cout<<"Select from menu...:";
        int selection;
        try {
            cin >> selection;
            if(!cin){
                cin.clear();                        
                cin.ignore(1000, '\n');             
                throw runtime_error("Invalid input. Please enter a number.");
            }
        } catch (runtime_error& e){
            cout << e.what() << endl;
            continue;                             
        }

        switch(selection){
            case 1:{
                cout<<"Enter Word to push: ";
                string word;
                cin>>word;

                stack.push(word);
                break;
            }

            case 2:
                cout<<"Performing UNDO....."<<endl;
                stack.pop();
                break;

            case 3:
                cout<<"Current Text: ";
                stack.printStack();
                break;

            case 4:
                cout<<"Exiting Program..."<<endl;
                isOn = false;
                break;

            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}