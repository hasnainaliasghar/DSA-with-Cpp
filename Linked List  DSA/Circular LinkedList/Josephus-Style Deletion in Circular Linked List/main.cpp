#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* next;
    Node(int val) {
        id = val;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        Node* temp = head;
        do {
            cout << temp->id << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }

    void eliminateThird() {
        int total = 0;
        Node* temp = head;
        do { total++; temp = temp->next; } while (temp != head);

        Node* current = head;
        Node* prev = head;

        while (total > 1) {
            for (int i = 0; i < 2; i++) {
                prev = current;
                current = current->next;
            }

            cout << "Removed: " << current->id << "\n";
            prev->next = current->next;
            Node* del = current;
            current = current->next;
            delete del;
            total--;
        }

        head = current;
        cout << "\nLast remaining student ID: " << head->id << "\n";
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.insert(50);
    cll.insert(60);

    cout << "Circular List:\n";
    cll.display();

    cout << "\nElimination:\n";
    cll.eliminateThird();

    return 0;
}