#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class LinkedList{
    private:
    
    Node* head;
    Node* tail;

    public:

    LinkedList(){
        head = tail = nullptr;
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if( head == nullptr){
            head = tail = newNode;
            return;
        }

        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty";
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void arrangebyvalue() {
    LinkedList odd;
    LinkedList even;
    Node* current = head;

    while(current != nullptr) {
        Node* next = current->next;          

        if(current->data % 2 != 0) {     
            odd.pushBack(current->data);
        } else {
            even.pushBack(current->data);
        }

        current = next;
    }


    if(odd.head != nullptr && even.head != nullptr) {
        odd.tail->next  = even.head;
        even.head->prev = odd.tail;
        head = odd.head;
        tail = even.tail;
    } else if(odd.head != nullptr) {
        head = odd.head;
        tail = odd.tail;
    } else {
        head = even.head;
        tail = even.tail;
    }
}

   void arrangebyPos(){

    Node* oddhead = nullptr;
    Node* evenhead = nullptr;

    Node* oddtail = nullptr;
    Node* eventail = nullptr;

    Node* current = head;
    int position = 1;
    while(current != nullptr){
        Node* nextval = current -> next;

        current -> next = nullptr;
        current -> prev = nullptr;

        if( position % 2  != 0){
            if(oddhead == nullptr) 
            {
                oddhead = oddtail = current;
            } else {
                oddtail -> next = current;
                current -> prev = oddtail;
                oddtail = current;
            } 

        } else {
            if(evenhead == nullptr){
                    evenhead = eventail = current;
            } else {
                eventail -> next = current;
                current -> prev = eventail;
                eventail = current;
            }
        }
        current = nextval;
        position++;
    }

    if(evenhead != nullptr){
        oddtail -> next = evenhead;
        evenhead -> prev = oddtail;
    }

    head = oddhead;
    tail = (evenhead != nullptr)? eventail : oddtail;

   }
};

int main(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);

    list.display();

    list.arrangebyPos();
    list.display();

    return 0;
}