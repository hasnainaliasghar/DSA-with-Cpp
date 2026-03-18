#include<iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int key){
    for(int i=0; i<size;i++){
        if(arr[i]== key){
            return i;
        }
    }
    return -1;
}

int main(){

    int index[] = {1,2,3,4,5};
    string books[] = {"The Great Gatsby", "1984", "To Kill a Mockingbird", "The Hobbit", "Hamlet"};

    int size = sizeof(index)/sizeof(index[0]);
    cout<<"Enter index to search book: ";
    int key;
    cin>>key;

    if(key> size){
        cout<<"Out of Range"<<endl;
        return 0;
    }

    int search = sequentialSearch(index,size,key);

    if(search == -1){
        cout<<"Book does not found"<<endl;
        return 0;
    }
    cout<<"Book at index "<<key<<" is "<<books[search]<<endl;

    return 0;
}