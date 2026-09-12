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

void PreOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    
}

void InOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

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

    cout<<"PreOrder : ";
    PreOrder(root);
    cout<<endl;

    cout<<"InOrder : ";
    InOrder(root);
    cout<<endl;

    cout<<"PostOrder : ";
    PostOrder(root);
    
    return 0;
}
