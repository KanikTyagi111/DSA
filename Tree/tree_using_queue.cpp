#include<iostream>
#include<queue>
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

int main() {
    int x, leftChild, rightChild;
    cin>>x;

    queue<Node *> q;
    Node *root = new Node(x);
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout<<"Enter left child of "<<temp->data<<" : ";
        cin>>leftChild;
        if(leftChild != -1) {
        temp->left = new Node(leftChild);
        q.push(temp->left);
        }

        cout<<"Enter right child of "<<temp->data<<" : ";
        cin>>rightChild;
        if(rightChild != -1) {
        temp->right = new Node(rightChild);
        q.push(temp->right);
        }
    }
}