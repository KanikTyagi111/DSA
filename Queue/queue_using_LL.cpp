#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }

};


class Queue {
    public:
    Node *head;
    Node *tail;
    int size;

    Queue() {
        head = tail = NULL;
        size = 0;
    }

    bool isEmpty() {
        return head == NULL;
    
    }


    void push(int value) {
        Node *newNode = new Node(value);

        if(newNode == NULL) {
            cout<<"queue is overflow\n";
            return;
            
        }

        else if(head == NULL) {
            head = tail = newNode;

            cout<<"Pushed "<<tail->data<<" into the queue\n";
            size++;
        }

        else {
            tail->next = newNode;
            tail = newNode;

            cout<<"Pushed "<<tail->data<<" into the queue\n";
            size++;
        }

       


    }


    void pop() {
        if(head == NULL) {
            cout<<"queqe is underflow\n";
            return;
        }
       
        Node *temp = head;
        cout<<"Popped "<<head->data<<" from the queue\n";
        head = head->next;

        if(head == NULL) {
            tail = NULL;
        }
        delete temp;
        size--;

        
    }

    int front() {
        if(head == NULL) {
            cout<<"queue is empty\n";
            return -1;
        }
        return head->data;
    }

    int isSize() {
        return size;
    }

    void display() {
        if(isEmpty()) {
            cout<<"Queue is empty\n";
            return;
        }
        Node *temp = head;
        cout<<"Queue is : ";
        while(!isEmpty()) {
            
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        
    }
    

    
};


int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.display();
    

    
    

    


    // int x = q.front();
    // if(!q.isEmpty()) {
    //     cout<<x<<endl;
    // }
    
}