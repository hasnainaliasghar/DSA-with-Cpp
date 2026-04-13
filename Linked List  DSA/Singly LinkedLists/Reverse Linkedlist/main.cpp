#include<iostream>
using namespace std;

/*
Practice LeetCode - https://leetcode.com/problems/reverse-linked-list/
*/

//Basic Code

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedNode{
    Node* head;
    
    public:
    LinkedNode(){
        head = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }

        temp -> next = newNode;
        newNode -> next = NULL;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data << " ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    void reverse(){
        Node* n = NULL;
        Node* c = head;
        Node* p = NULL;

        while(c != NULL){
            n = c -> next;
            c -> next = p;

            p = c;
            c = n;
        }

        head = p;
    }
};

int main(){
    LinkedNode n;
    n.push(10);
    n.push(20);
    n.push(30);

    n.print();

    n.reverse();
    n.print();
}

