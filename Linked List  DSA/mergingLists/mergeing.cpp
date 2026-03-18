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

   Node* mergeSorted(Node* head1, Node* head2){
        Node* head3 = nullptr;

        while(head1 != nullptr && head2 != nullptr){
            if(head1->data <= head2->data){
                push_back(head1->data);
                head1 = head1->next;
            } else {
                push_back(head2->data);
                head2 = head2->next;
            }
        }

        while(head1 != nullptr){
            push_back(head1->data);
            head1 = head1->next;
        }

        while(head2 != nullptr){
            push_back(head2->data);
            head2 = head2->next;
        }

        return head3;
    }

    Node* getHead(){
        return head;
    }
};

int main(){
    LinkedList list1, list2, list3;

    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);
    list1.printList();  

    list2.push_back(2);
    list2.push_back(4);
    list2.push_back(6);
    list2.printList();  

    list3.mergeSorted(list1.getHead(), list2.getHead());
    list3.printList();  
}