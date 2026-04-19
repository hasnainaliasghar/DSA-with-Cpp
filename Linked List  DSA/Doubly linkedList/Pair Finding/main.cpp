#include<iostream>
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

        void pairs(int sum){
            if(head == nullptr){
                cout<<"List is empty"<<endl;
                return;
            }

            bool found = false;

            Node* start = head;
            

            while(start != nullptr){
                Node* end = tail;
                while(end > start){
                    if(start -> data + end -> data == sum and start != end){
                        cout<<"("<<start ->data <<","<<end->data<<")"<< ", ";
                        found = true;
                    }

                    end = end -> prev;
                }

                start = start -> next;
            }

            if(!found){
                cout<<"No pairs Found"<<endl;
                return;
            }
        }

    };

    int main(){
        LinkedList ll;
        ll.push_back(1);
        ll.push_back(2);
        ll.push_back(3);
        ll.push_back(4);
        ll.push_back(5);
        ll.push_back(6);
        ll.push_back(7);
        ll.push_back(8);
        ll.push_back(9);

        ll.displayList();

        ll.pairs(10);

    }