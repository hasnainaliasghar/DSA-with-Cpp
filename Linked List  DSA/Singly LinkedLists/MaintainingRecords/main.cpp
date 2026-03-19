#include<iostream>
using namespace std;

class intNode{
    int data;
    intNode* next;

    intNode(int val){
        data = val;
        next = nullptr;
    }
};