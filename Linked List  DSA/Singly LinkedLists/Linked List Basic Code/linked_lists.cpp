#include<iostream>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    
    Node* head;
    public:

    List(){
        head = NULL;
    }

    void push_front(int val){
        Node *newnode = new Node(val);
        if (head == NULL){
            head = newnode;
            return;
        }

        newnode -> next = head;
        head = newnode;
    }

    void push_back(int val){
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp ->next = newnode;
    }

    void push_pos(int val, int pos){

        if(pos == 1){
            push_front(val);
            return;
        }

        Node* newnode = new Node(val);
        Node* temp = head;

        for(int i = 1; temp != NULL && i < pos-1; i++){
            temp = temp->next;
        }

        if(temp == NULL){
            push_back(val);
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    
    void pop_front(){
        if(head == NULL){
            return;
        }

        Node*temp = head;
        head = head -> next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL) return; // empty list

        if(head->next == NULL){ // only one node
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        // move to second last node
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        temp->next = NULL;  // remove link
        delete temp->next;  // delete last node
        
    }

    void pop_val(int val){

        if(head == NULL) return;

        if(head->data == val){
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL && temp->next->data != val){
            temp = temp->next;
        }

        if(temp->next == NULL) return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    //Searching Through Linked list
    void search(int svalue){
        int count = 0;
        Node* current = head;
        while(current != NULL){
            if(current-> data == svalue){
                cout<<"Elemnt Founded at "<<count<<endl;
                return;
            } else {
                current = current -> next;
                count++;
            }
        }

        cout<<"Element not found"<<endl;
    }

   void merge(List& list) {
    List* list2 = &list;
    if (head == NULL) {  
        head = list2->head;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) { 
        temp = temp->next;
    }

    temp->next = list2->head; 
}

    Node* gethead(){
        return head;
    }

    void bubblesort(){
        if(head == nullptr) return;


        bool swapped;
        Node* current;
        Node* lastptr = nullptr;

        do{
            swapped = false;
            current = head;

            while(current -> next != lastptr){
                if(current -> data > current -> next -> data){
                    swap(current ->data , current ->next -> data);
                    swapped = true;
                }

                current = current -> next;
            }
            lastptr = current;
        }while (swapped);
        
    }

    void printList(){
        Node*temp = head;
        while(temp != NULL){
            cout<< temp -> data << " ";
            temp = temp -> next;
        }

        cout<<endl;
    }
    
    void valuecount(int val){
        int count = 0;
        Node*temp = head;

        while(temp!= NULL){
            if(temp -> data == val){
                count ++;
            }
            temp = temp -> next;
        }

        cout<<"The "<<val<<" comes "<<count<<" times."<<endl;
    }

    void reverse(){
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while(current!= NULL){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void removeDuplicate(){
          Node* current = head;

    while (current != nullptr) {
        Node* runner = current;
        // Check all following nodes for duplicates
        while (runner->next != nullptr) {
            if (current->data == runner->next->data) {
                //Remove duplicate node
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp; // free memory
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
};

int main() {

    List ll;
    ll.push_front(1);
    ll.push_back(3);
    ll.push_pos(2,2);
    ll.push_back(4);
    ll.push_front(0);
    ll.printList();

    ll.pop_front();
    ll.pop_back();
    ll.pop_val(2);
    ll.printList();

    ll.search(5);

    List ll2;

    ll2.push_back(4);

    ll.merge(ll2);
    ll.printList();

    ll.push_front(5);
    ll.push_front(5);
    ll.push_pos(5,3);
    ll.push_back(5);
    ll.printList();

    ll.valuecount(5);
    ll.reverse();
    ll.printList();
    ll.removeDuplicate();
    ll.printList();

    ll.bubblesort();
    ll.printList();

    return 0;
}