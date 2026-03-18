#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
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
    queue <string> waitingList;
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

    void sortBooks(){
        if(head == nullptr) return;

        bool swapped;
        Node* current;
        Node* lastptr = nullptr;

        do{
            swapped = false;
            current = head;

            while(current -> next != lastptr){
                if(current->data > current->next ->data){
                    swap(current->data, current -> next -> data);
                    swapped = true;
                }

                current = current -> next;
            }

            lastptr = current;
        }while(swapped);
    }

    bool searchBook(string book){
        
        if(head == nullptr){
            cout<<"Add books first"<<endl;
            return false;
        }

        int count = 1;
        Node* current = head;

        while(current != nullptr){
            
            if(current -> data == book){
                cout<<"Found Book at node "<<count<<endl;
                return true;
            }
            current = current -> next;
            count ++;
            
        }

        cout<<"Book is not added yet"<<endl;
        return false;
    }

    void printBooks(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<endl;
            temp = temp -> next;
        }

        cout<<endl;
    }

    void addToWaitingList(string name) {
        waitingList.push(name);
        cout << name << " added to the waiting list.\n";
    }

    void showWaitingList() {
        cout << "Waiting List Count: " << waitingList.size() << " people.\n";
    }

};

int main(){
    LinkedList lib;
    cout<<"---Present Books---"<<endl;
    lib.add_book("Harry Potter");
    lib.add_book("Hobbit");
    lib.add_book("Forty rules of Love");
    lib.add_book("Rumi's Secret");
    lib.add_book("Alice");
    lib.sortBooks();
    lib.printBooks();

    cout<<endl<<"--Search Book--"<<endl;
    string search;
    cout<<"Enter book name: ";
    getline(cin,search);
    bool found = lib.searchBook(search);

    //Adding to waiting list
    if(found){
        lib.addToWaitingList(search);
        lib.showWaitingList();
    }
    
    return 0;
}