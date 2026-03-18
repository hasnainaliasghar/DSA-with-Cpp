#include<iostream>
using namespace std;

//creating a node
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    
    public:
    LinkedList(){
        head = nullptr;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        newNode-> next = head;
        head = newNode;
    }

};

int main(){
    cout << "sample";
}