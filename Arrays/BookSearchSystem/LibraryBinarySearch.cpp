#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size, int key){
    int left = 0, right = size -1 ;
    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] > key){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
};

int main(){
    //sorted array is required for Binary Search
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

    int search = BinarySearch(index,size,key);

    if(search == -1){
        cout<<"Book does not found"<<endl;
        return 0;
    }
    cout<<"Book at index "<<key<<" is "<<books[search]<<endl;

    return 0;
}