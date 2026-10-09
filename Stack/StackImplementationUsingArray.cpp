#include<iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

    public:
    Stack(int n) 
    {
        arr = new int[n];
        top = -1;
        size = n;
    }

    bool full()
    {
        return top == size-1;
    }

    bool empty()
    {
        return top == -1;
    }

    void push(int val)
    {
        if(full()) {
            cout<<"Stack is Overflow\n";
            return;
        }

        top++;
        arr[top] = val;
        cout<<"Pushed "<<val<<" into the stack\n";

    }

    void pop()
    {
        if(empty())
        {
            cout<<"Stack is Underflow\n";
            return;
        }

        cout<<"Popped "<<arr[top]<<" from the stack\n";
        top--;
    }

    int peek()
    {
        if(empty())
        {
            cout<<"Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

};

int main() 
{
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    

    s.pop();

    
   
    int x = s.peek();
    if(x != -1)
    {
        cout<<x;
    }

    return 0;
}