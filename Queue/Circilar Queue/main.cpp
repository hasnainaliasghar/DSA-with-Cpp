#include<iostream>
using namespace std;

class CircularQueue{
    string* arr;
    int currentSize;
    int f,r, cap;

    public:
    CircularQueue(int size){
        cap = size;
        arr = new string[cap];
        currentSize = 0;
        f = 0;
        r = -1;
    }
    
    void enqueue(string data){

        if(currentSize == cap){
            cout<<"Array is full"; 
            return;
        }

        r = (r+1)%cap;
        arr[r] = data;
        currentSize++;
    }

    void pop(){
        if(currentSize == 0){
            return;
        }

        f = (f+1) % cap;
        currentSize--;
    }

    string front(){
        return arr[f];
    }

    void display(){
    if(currentSize == 0){
        cout << "Queue is empty\n";
        return;
    }

    int i = f;
    int count = 0;

    while(count < currentSize){
        cout << arr[i] << " ";
        i = (i + 1) % cap;
        count++;
    }
    cout << endl;
}
};

int main(){
    CircularQueue que(5);
    que.enqueue("CAR101"); 
    que.enqueue("CAR102");
    que.enqueue("CAR103");

    que.display();

    que.pop();
    que.pop();

     que.display();

    que.enqueue("CAR104");
    que.enqueue("CAR105");
    que.enqueue("CAR106");

     que.display();

    que.pop();
    que.enqueue("CAR107");
    que.enqueue("CAR108");
    
     que.display();

     que.enqueue("CAR109");
}