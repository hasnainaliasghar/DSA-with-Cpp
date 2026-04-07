#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
       data = val;
       prev = next = nullptr;
    }


};

class Queue{
    Node* head;
    Node* tail;

    public:
    Queue(){
        head = tail = nullptr;
    }

    void addQueue(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
       
       tail -> prev = tail;
       tail -> next = newNode;
       tail = newNode;

    }
   
    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }

    void dequeue(){
       
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return;
        }
       
       
        Node* temp = head;
        if(head == tail){
            delete head;
            head = tail = nullptr;
            cout<<"Stack is Empty"<<endl;
            return;
        }
       
       
        head = head -> next;
        head -> prev = nullptr;
        temp->next = nullptr;
       
        delete temp;
       
    }


    void display(){
        Node* temp = head;

        while(temp != nullptr){
            cout<<temp -> data<< " ";
            temp = temp -> next;
        }
        cout<<endl;

    }
};

int main(){
    Queue queue;
    queue.addQueue(10);
    queue.addQueue(20);
    queue.addQueue(30);
    queue.addQueue(40);
    cout<<endl;
    queue.display();
    queue.dequeue();
    queue.display();

    return 0;
}