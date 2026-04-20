#include<iostream>
using namespace std;

class Node{
public:
    int pq;
    char val;
    Node* next;

    Node(int p, char d){
        pq = p;
        val = d;
        next = NULL;
    }
};

class PriorityQueue{
private:
    Node* front;

public:
    PriorityQueue(){
        front = NULL;
    }

    void push(int priority, char value){
        Node* newNode = new Node(priority, value);

        // Case 1: empty OR highest priority
        if(front == NULL || 
           priority < front->pq || 
           (priority == front->pq && value < front->val)){
            
            newNode->next = front;
            front = newNode;
            return;
        }

        Node* temp = front;

        while(temp->next != NULL &&
             (temp->next->pq < priority ||
             (temp->next->pq == priority && temp->next->val < value))){
            
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop(){
        if(front == NULL) return;
        front = front->next;
    }

    void display(){
        Node* temp = front;
        while(temp){
            cout << "(" << temp->pq << "," << temp->val << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};