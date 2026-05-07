#include<iostream>
using namespace std;

class Node{
    public:

    int value;
    string key;
    Node* next;

    Node(int val, string k){
        value = val;
        key = k;
        next = NULL;
    }
};

class HashMap{
    private:
    static const int SIZE = 10;
    Node* table[SIZE];

    int hashfunc(string key){
        int count = 0; 
        for (char c: key){
            count += c;
        }

        return count % SIZE;
    }

    public:

    HashMap(){
        for(int i=0; i< SIZE; i++){
            table[i] = nullptr;
        }
    }

    void insertval(int value, string key){
        int index = hashfunc(key);

        Node* newNode = new Node(value, key);

        if(table[index] == nullptr){
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while(temp -> next != nullptr){
                if(temp -> key == key){
                    cout<<"Already exists"<<endl;
                    return;
                }

                if(temp -> next == nullptr) break;
                temp = temp -> next;
            }

            temp -> next = newNode;


        }
    }

};