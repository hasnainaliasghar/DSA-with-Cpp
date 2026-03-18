#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class SNode{
    public:
    string data;
    Node* next;

    SNode(string name){
        data = name;
        next = nullptr;
    }
};

class LinkedList{
    Node* head1;
    SNode* head2;
    
    public:
    LinkedList(){
        head1 = nullptr;
        head2 = nullptr;
    }

    void push_front(int val, string name){
        Node* newNode = new Node(val);
        SNode* newSNode = new SNode(name);
        if(head1==nullptr){
            head1 = newNode;
            head2 = newSNode;
            return;
        }
        newNode-> next = head1;
        newSNode -> next = head2;
        head1 = newNode;
        head2 = newSNode;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        SNode* newSNode = new SNode(name);
        if(head1==nullptr){
            head1 = newNode;
            head2 = newSNode;
            return;
        }

        Node* temp1 = head1;
        SNode*
        while(temp1 ->next != nullptr){
            temp1 = temp1 -> next;
        }
        temp -> next = newNode;
        temp ->next = newSNode;
    }

    void printList(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data <<" -> ";
            temp = temp->next;
        }
        cout<<"null"<<endl;
    }

    void mergeList(LinkedList &list){
        LinkedList* list2 = &list;
        if(head == nullptr){
            head = list2 -> head;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp -> next = list2 -> head;
    }

    void removeDuplicate(){
        Node* current = head;

        while(current != nullptr){
            Node* runnerptr = current;

            while(runnerptr -> next != nullptr){
                if(current->data == runnerptr ->next -> data){
                    Node* temp = runnerptr -> next;
                    runnerptr->next = runnerptr ->next -> next;
                    delete temp;
                } else {
                    runnerptr = runnerptr ->next;
                }
            }

            current = current -> next;
        }
    }
    
    

};