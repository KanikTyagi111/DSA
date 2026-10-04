#include<iostream>
using namespace std;

class MaxHeap
{
    int* arr;
    int size; // size of actual heap
    int total_size; // size of the array

    public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int val)
    {
        if(size == total_size)
        {
            cout<<"Heap Overflow";
            return;
        }

        arr[size] = val;
        int i = size;
        size++;

        // compare it with its parent

        while(i > 0 && arr[(i-1)/2] < arr[i])
        {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }

        cout<<arr[i]<<" is inserted into the heap"<<endl;
    }

    void print()
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    MaxHeap h(6);
    h.insert(4);
    h.insert(14);
    h.insert(11);
}