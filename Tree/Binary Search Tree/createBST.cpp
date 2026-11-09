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

bool search(Node* root, int target) {
    if(!root)
    return 0;

    if(root->data == target)
    return 1;

    if(target < root->data)
    return search(root->left,target);
    else
    return search(root->right,target);
}

int main() {
    int arr[] = {3,7,4,1,6,8};

    Node* root = NULL;
    for(int i=0; i<6; i++) {
        root = insert(root,arr[i]);
    }

    cout<<search(root,16);
    // inorder(root); // return sorted array

    return 0;
}