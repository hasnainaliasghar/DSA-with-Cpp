#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
#include<stack>
using namespace std;

//Task - 2  Construct a Binary Tree from the Array
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree{
    Node* root;

    void deletedeepest(Node* root, Node* last){
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

    void collectValues(Node* node, vector<int>& vals){
        if(!node) return;

        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            vals.push_back(curr -> data);

            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
    }

    Node* insertBST(Node* node, int val){
        if(node == NULL){
            return new Node(val);
        }

        if(val < node->data){
            node -> left = insertBST(node -> left,val);
        } else {
            node -> right = insertBST(node -> right, val);
        }

        return node;
    }

    void clearTree(Node* node){
        if(!node) return;
        clearTree (node -> left);
        clearTree(node -> right);
        delete node;
    }

    public:
    
    BinaryTree(){
        root = nullptr;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(root == nullptr){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp ->left){
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

        if (root->data == dataVal && root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
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

        if (target) {
            if (target == last) { 
                deletedeepest(root, last);
            } else {
                int x = last->data;
                deletedeepest(root, last);
                target->data = x;
            }
        }
    }

//Task-3 Remove DUplicates
 void removeDuplicates() {
    if (root == nullptr) {
        cout << "Tree is already Empty" << endl;
        return;
    }

    unordered_set<int> seen;
    vector<int> toDelete;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);

        if (seen.count(curr->data)) {
            toDelete.push_back(curr->data);
        } else {
            seen.insert(curr->data);
        }
    }

    for (int val : toDelete) {
        deleteval(val);
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

    void convertToBST(){
        if(root == nullptr){
            cout<<"Tree is empty"<<endl;
            return;
        }

        vector<int> vals;
        collectValues(root,vals);

        clearTree(root);
        root = nullptr;

        for(int val : vals) {
            root = insertBST(root,val);
        }

        inorderTraversal();
    }

    void inorderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        stack<Node*> s;
        Node* temp = root;
        while (temp != nullptr || !s.empty()) {
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top(); s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }

};

int main() {
    BinaryTree bt;
    int num;
    cout << "Enter the size of array: ";
    cin >> num;

    int arr[num];                        
    for (int i = 0; i < num; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < num; i++) bt.insert(arr[i]);

    cout << "Original:  "; bt.display();
    bt.removeDuplicates();
    cout << "No Dupes:  "; bt.display();
                         
    cout << "BST order: "; bt.convertToBST();
}