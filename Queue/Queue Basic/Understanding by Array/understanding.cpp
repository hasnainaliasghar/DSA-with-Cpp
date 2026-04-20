#include <iostream>
using namespace std;

const int MAX = 5;

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1) // first element
            front = 0;

        arr[++rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        front++;

        // Reset queue if empty again
        if (front > rear) {
            front = rear = -1;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.printQueue();

    queue.dequeue();

    queue.enqueue(60);
    queue.printQueue();

    return 0;
}
