#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    string data;
    Node* next;

    Node(string val){
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

    void add_book(string book){
        Node* newNode = new Node(book);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    void searchBook(string book){
        int count = 1;
        if(head == nullptr){
            cout<<"Add books first"<<endl;
            return;
        }

        Node* current = head;
        if(current -> data == book){
            cout<<"Found book at node "<<count<<endl;
        }

        while(current != nullptr){
            current = current -> next;
            if(current -> data == book){
                cout<<"Found Book at node "<<count<<endl;
                return;
            }
            count ++;
        }

        cout<<"Book is not added yet"<<endl;
        return;
    }

    void printBooks(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<endl;
            temp = temp -> next;
        }

        cout<<endl;
    }

};

int main(){
    LinkedList lib;
    cout<<"---Present Books---"<<endl;
    lib.add_book("Harry Potter");
    lib.add_book("Hobbit");
    lib.add_book("Forty rules of Love");
    lib.add_book("Rumi's Secret");
    lib.printBooks();

    cout<<endl<<"--Search Book--"<<endl;
    string search;
    cout<<"Enter book name: ";
    getline(cin,search);

    lib.searchBook(search);
    return 0;
}