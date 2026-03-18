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
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp ->next != nullptr){
            temp = temp -> next;
        }
        temp -> next = newNode;
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

int main(){
    LinkedList list1, list2;
    list1.push_back(1);
    list1.printList();

    list2.push_front(0);
    list2.printList();

    list1.mergeList(list2);
    list1.printList();

}