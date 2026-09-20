#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root,int val) {
    if(root == NULL) {
        Node* temp = new Node(val);
        return temp;
    }

    if(val < root->data) {
        root->left = insert(root->left,val);
    }
    else {
        root->right = insert(root->right,val);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    int arr[] = {3,4,8,5,7,10};

    Node* root = NULL;
    for(int i=0; i<6; i++) {
        root = insert(root,arr[i]);
    }

    inorder(root);

    return 0;
}