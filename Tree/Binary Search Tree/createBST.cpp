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

Node* deleteNode(Node* root, int target) {
        if(!root)
        return NULL;

        if(target < root->data) {
            root->left =  deleteNode(root->left,target);
            return root;
        }
        else if(target > root->data) {
            root->right =  deleteNode(root->right,target);
            return root;
        }
        else {
            // leaf node
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
            

            // 1 child exist
            else if(!root->left) { // right child exist
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right) { // left child exist
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // 2 child exist
            else {
                // find the greatest element in left side
                Node* child = root->left;
                Node* parent = root;

                while(child->right) {
                    parent = child;
                    child = child->right;
                }

                if(root != parent) {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }

        }
    }

int main() {
    int arr[] = {3,7,4,1,6,8};

    Node* root = NULL;
    for(int i=0; i<6; i++) {
        root = insert(root,arr[i]);
    }

    deleteNode(root,4);
    // cout<<search(root,16);
    inorder(root); // return sorted array

    return 0;
}