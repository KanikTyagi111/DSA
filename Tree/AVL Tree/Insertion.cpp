#include<iostream>
using namespace std;

class Node {
    public:
    int data, height;
    Node *left, *right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root) {
    if(!root)
    return 0;

    return root->height;
}

int getBalance(Node* root) {
    return getHeight(root->left)-getHeight(root->right);
}

Node* rightRotation(Node* root) {
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insert(Node* root, int key) {
    if(!root)
    return new Node(key);

    if(key < root->data) {
        root->left = insert(root->left, key);
    }
    else if(key > root->data) {
        root->right = insert(root->right, key);
    }
    else {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // balancing check
    int balance = getBalance(root);

    // left left case
    if(balance > 1 && key < root->left->data) {
        rightRotation(root); // top node
    }
    // right right case
    else if(balance < -1 && key > root->right->data) {
        leftRotation(root); // top node
    }
    // left right case
    else if(balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left); // middle node
        return rightRotation(root); // top node
    }
    // right left case
    else if(balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right); // middle node
        return leftRotation(root); // top node
    }
    // no unbalancing
    else {
        return root;
    }
}

void inOrder(Node* root) {
    if(!root)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if(!root)
    return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 50);
    root = insert(root, 90);
    root = insert(root, 37);
    root = insert(root, 93);
    root = insert(root, 67);
    root = insert(root, 33);
    root = insert(root, 56);

    cout<<"InOrder : "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"PreOrder : "<<endl;
    preOrder(root);
    
}