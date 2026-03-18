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
    
    //Take union accepts 2 functions
    void take_union(LinkedList &list){
        //1. merging lists
        mergeList(list);
        //2. removing duplicates
        removeDuplicate();
    }

    void take_intersection(LinkedList &list2) {
        LinkedList *list = &list2;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            bool found = false;
            Node* runner = list ->head;
            while (runner != nullptr) {
                if (runner->data == current->data) {
                    found = true;
                    break;
                }
                runner = runner->next;
            }

            if (found) {
                prev = current;
                current = current->next;
            } else {
                if (prev != nullptr)
                    prev->next = current->next;
                else
                    head = current->next;

                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }

    }

};

int main(){
    LinkedList list1, list2, list3;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.printList();

    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);
    list2.printList();

    list3.push_back(1);
    list3.push_back(2);
    list3.push_back(3);

    list1.take_union(list2);
    list1.printList();

    list1.take_intersection(list3);
    list1.printList();

}