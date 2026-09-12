#include<iostream>
using namespace std;

class Queue {
    public:
    int *arr;
    int front, rear;
    int size;

    Queue(int n) {
        arr = new int[n];
        front = rear = -1;
        size = n;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void push(int value) {
        if(isEmpty()) {
            front = rear = 0;
            arr[0] = value;
        }
        else if(isFull()) {
            cout << "Queue is Overflow\n";
            return;
        }
        else {
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
        cout << "Pushed " << value << " into the queue\n";
    }

    void pop() {
        if(isEmpty()) {
            cout << "Queue is Underflow\n";
            return;
        }
        
        cout << "Popped " << arr[front] << " from the queue\n";
        
        // FIX: Put the pointer increment inside an 'else' block
        if(front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % size;
        }
    }

    int start() {
        if(isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        else {
            return arr[front];
        }
    }
};

int main() {
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    

    q.pop();
     
    
    

    int x = q.start();
    if(!q.isEmpty()) {
        cout<<"Front Element of queue : ";
        cout<<x<<endl;
    }


}
