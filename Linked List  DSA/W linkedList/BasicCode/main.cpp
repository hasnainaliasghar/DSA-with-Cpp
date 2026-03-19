#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
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

        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == nullptr){
                head = tail = newNode;
                return;
            }

            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;

        }

        void push_back(int val){
            Node* newNode = new Node(val);
            if(tail == nullptr){
                head = tail = newNode;
                return;
            }

            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }

        void pop_front(){
            if(head == nullptr){
                return;
            }
            Node* temp = head;
            head = head-> next;
            if(head != nullptr){
                head -> prev = nullptr;
            } else {
                tail = nullptr;
            }

            delete temp;
        }

    void deleteByValue(int val){

        if(head == NULL){
            return;
        }

        if(head->data == val){
            pop_front();
            return;
        }

        Node* temp = head;

        while(temp != NULL && temp->data != val){
            temp = temp->next;
        }

        if(temp == NULL){
            cout << "No such value exists";
            return;
        }

        if(temp == tail){
            tail = temp->prev;
        }

        if(temp->next){
            temp->next->prev = temp->prev;
        }

        if(temp->prev){
            temp->prev->next = temp->next;
        }

        delete temp;
    }

        void displayList(){

            if(head == nullptr){
                return;
            }

            Node* temp = head;
            while (temp != nullptr)
            {
                cout<<temp ->data<<" -> ";
                temp = temp -> next;
            }

            cout<<"null"<<endl;
            
        }


};

int main(){
    LinkedList list;
    list.push_front(1);
    list.push_back(2);
    list.displayList();
    list.push_back(3);

    list.pop_front();
    list.displayList();
    list.deleteByValue(2);
    list.displayList();
}