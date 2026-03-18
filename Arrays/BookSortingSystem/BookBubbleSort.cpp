#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void bubbleSort(string arr[], int size){
    for(int i = 0; i<size-1;i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main() {
    // Array with 10 different book names
    string books[] = {
        "Dracula",
        "Brave New World",
        "Frankenstein",
        "Alice in Wonderland",
        "Jane Eyre",
        "Catch-22",
        "Great Expectations",
        "Inferno",
        "Emma",
        "Dune"
    };

    int n = sizeof(books) / sizeof(books[0]);

    cout << "Unsorted List of Books:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 <<". "<<books[i] << endl;
    }

    cout<<endl;

    bubbleSort(books,n);

    cout<<endl;

    cout << "Sorted List of Books:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 <<". "<<books[i] << endl;
    }

    return 0;
}