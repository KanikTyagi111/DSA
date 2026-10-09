#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    

    Node(int val)
    {
        data = val;
        next = NULL;
        
    }
};

class Stack
{
    public:
    Node* top;
    int size;

    Stack() {
        top = NULL;
        size = 0;
    }

    bool empty()
    {
        return top == NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);

        if(newNode == NULL)
        {
            cout<<"Stack is Overflow\n";
            return;
        }

        newNode->next = top;
        top = newNode;
        cout<<"Pushed "<<val<<" into the stack\n";
        size++;
    }

    void pop()
    {
        if(empty())
        {
            cout<<"Stack is Underflow\n";
            return;
        }

        Node* temp = top;
        cout<<"Popped "<<top->data<<" from the stack\n";
        top = top->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if(empty())
        {
            cout<<"Stack is Empty\n";
            return -1;
        }

        return top->data;
    }

    int Size()
    {
        return size;
    }

};

int main() {
    Stack s;

    s.push(11);
    s.push(21);
    s.push(31);

   

    s.pop();
    s.pop();
    cout<<"Size : "<<s.Size()<<endl;

    int x = s.peek();
    if(x != -1)
    {
        cout<<x;
    }
    return 0;
}
