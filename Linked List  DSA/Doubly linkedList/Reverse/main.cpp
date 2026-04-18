#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        next = nullptr;
        prev = nullptr;
        data = val;
    }

};

class LinkedList{
    private:
    
    Node* head;
    Node* tail;

    public:

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = tail = newNode;
            return;
        }

        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }

    void display(){
        Node* temp = head;
        if(temp == nullptr){
            cout<<"List is empyt";
            return;
        }

        while(temp != nullptr){
            cout<<temp -> data <<" ";
            temp = temp -> next;
        }

        cout<<endl;
    }

    void reverse(){
        Node* current = head;
        Node* temp = nullptr;
        while(current != nullptr){
            temp = current -> prev;
            current -> prev = current -> next;
            current -> next = temp;

            current = current -> prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }
};

int main(){
    LinkedList ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);

    ll.display();

    cout<<endl;
    ll.reverse();
    ll.display();
}