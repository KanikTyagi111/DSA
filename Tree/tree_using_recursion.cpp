#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *binaryTree() {
    int x;
    
    cin>>x;

    if(x == -1) {
        return NULL;
    }

    Node *temp = new Node(x);

    cout<<"Enter the left child of "<<x<<" : ";

    temp->left = binaryTree();

    cout<<"Enter the right child of "<<x<<" : ";
    
    temp->right = binaryTree();

    return temp;
}

int main() {
    cout<<"Enter the root element : ";
    Node *root;
    root = binaryTree();
    return 0;
}
