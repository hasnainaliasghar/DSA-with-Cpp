#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // Find the string that comes first in the dictionary
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Move the "earliest" string found to its correct position
        swap(arr[min_idx], arr[i]);
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

    selectionSort(books,n);

    cout<<endl;

    cout << "Sorted List of Books:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i+1 <<". "<<books[i] << endl;
    }

    return 0;
}