#include<iostream>
#include<queue>
using namespace std;
class Node{     //the node class will be almost same as in LinkedList
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    private:
    Node* root;

    void deletedeepest(Node* last){
        queue < Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp -> left){
                if(temp ->left == last){
                    delete temp -> left;
                    temp -> left = NULL;
                    return;
                } else {
                    q.push(temp -> left);
                }
            }

            if(temp -> right){
                if(temp -> right == last){
                    delete temp-> right;
                    temp -> right = NULL;
                    return;
                } else {
                    q.push(temp-> right);
                }
            }
        }
    }
    
    public:
    BinaryTree(){
        root = NULL;
    }

    void insert(int val){
        Node* newNode = new Node(val);

        if(root == NULL){
            root = newNode;
            root -> left = NULL;
            root -> right = NULL;
            return; 
        }

        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp -> left){
                q.push(temp -> left);
            } else {
                temp -> left = newNode;
                return;
            }

            if(temp -> right){
                q.push(temp -> right);
            } else {
                temp -> right = newNode;
                return;
            }
        }
        
    }

    void deleteval(int dataVal){
        if(root == NULL){
            cout<<"Tree is already NULL can not delte value"<<endl;
            return;
        }

        Node* target = NULL;
        Node* last = NULL;

        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp -> data == dataVal){
                target = temp;
            }

            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp->right){
                q.push(temp -> right);
            }
            last = temp;
        }

        if(target){
            int x = last -> data;
            deletedeepest(last);
            target -> data = x;
        }
    }

    void display(){
        if(root == NULL){
            cout<<"Add element to tree first"<<endl;
            return;
        }

        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            cout<<temp ->data << " ";

            if(temp -> left){
                q.push(temp ->left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
        cout<<endl;
    }
    
};

int main(){
    BinaryTree bt;
    bt.insert(8);
    bt.insert(7);
    bt.insert(6);
    bt.insert(5);
    bt.insert(4);
    bt.insert(3);

    bt.display();
    bt.deleteval(7);
    bt.display();
    return 0;
}