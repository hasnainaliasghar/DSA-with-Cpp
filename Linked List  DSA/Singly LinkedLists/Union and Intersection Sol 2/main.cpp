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

class LinkedList{
    private:
        Node * head;
    
    public:
        
    LinkedList(){
        head = nullptr;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = newNode;
            return;
        }

        newNode -> next = head;
        head = newNode;
    }

    void display(){
        Node* temp = head;
        if(temp == nullptr){
            cout<<"Empty"<<endl;
            return;
        }

        while(temp != NULL){
            cout<<temp -> data <<" ";
            temp = temp -> next;
        }

        cout<<endl;
    }

    void intersection(LinkedList &list){
        LinkedList* list1 = &list;

        Node* current = head;
        cout<<"Intersection: ";
        while(current != NULL){
            Node* runner = list1 -> head;

            while(runner != nullptr){

                if(runner -> data == current -> data){
                    cout<<current -> data << " ";
                }
                runner = runner -> next;
            }
            current = current -> next;
        }
    }

    void Union(LinkedList &other){
        LinkedList* list = &other;

        cout<<"Union: ";
        Node* current = list -> head;
        while(current != nullptr){
            Node* runner = head;
            bool found = false;
            while(runner != nullptr){
                if(current -> data == runner -> data){
                    found = true;
                    break;
                }
                runner = runner -> next;
            }

            if(!found){
                push_front(current-> data);
            }

            current = current -> next;
            
        }

        display();
    }


};

int main(){
    LinkedList l1,l2;

    l1.push_front(30);
    l1.push_front(20);
    l1.push_front(10);

    l2.push_front(20);
    l2.push_front(10);
    l2.push_front(50);

    l1.display();
    l2.display();

    l1.intersection(l2);
    l1.Union(l2);
}