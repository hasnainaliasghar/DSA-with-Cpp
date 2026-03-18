#include<iostream>
using namespace std;

//creating a node
class Node{
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
    
};