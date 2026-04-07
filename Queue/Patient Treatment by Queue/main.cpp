#include<iostream>
using namespace std;

class Node{
    public:
    int patient_id, p_age;
    string p_name,stymptoms;
    Node* next;

    Node(int id, string name, int age, string symp){
        patient_id = id;
        p_age = age;
        p_name = name;
        stymptoms = symp;

        next = nullptr;
    }


};

class Queue{
    Node* head;
    Node* tail;
    Node* current;

    public:
    Queue(){
        current = head = tail = nullptr;
    }

    void addQueue(int id,string name, int age, string symp){
        Node* newNode = new Node(id,name,age,symp);
        if(head == nullptr){
            current = head = tail = newNode;
            cout<<"Patient Added: "<< newNode ->p_name<<endl;
            return;
        }


       tail -> next = newNode;
       tail = newNode;
       cout<<"Patient Added: "<< newNode ->p_name<<endl;

    }

    Node* dequeue(){
        Node* temp = current;
        current = current-> next;
        return temp;
    }

    void treatePatient(){
        cout<<endl;
        Node* next_patient = dequeue();
        cout<<"Treating Patient: "<< next_patient -> p_name<<endl<<endl;
        
    }

    void nextTreat(){
        cout<<"Next Patient to Treat: "<<endl;
        cout<<"ID: "<<current -> patient_id
        <<", Name: " <<current -> p_name
        <<", Age: "<< current -> p_age 
        <<", Symptoms: " << current -> stymptoms<<endl;

    }

    void displayPatientsdetails(){
        Node* temp = current;
        cout<<"Current Emergency Queue: "<<endl;

        while(temp != nullptr){
            cout<<temp->patient_id<<" - "<<temp -> p_name<<" - "<<temp->p_age <<" - "<<temp->stymptoms<<endl;
            temp = temp -> next;
        }
        cout<<endl;

    }
};

int main(){
    Queue queue;
    queue.addQueue(101, "Ahmed", 45, "Chest pain");
    queue.addQueue(102, "Sonia", 30, "High fever");
    queue.addQueue(103, "Bilal", 60, "Breathing difficulty");

    queue.treatePatient();

    queue.addQueue(104, "Mina", 28, "Migraine");
    queue.addQueue(105, "Zaid", 50, "High blood pressure");

    cout<<endl;
    queue.nextTreat();

    cout<<endl;
    queue.displayPatientsdetails();

    return 0;
}