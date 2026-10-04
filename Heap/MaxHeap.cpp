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

    void heapify(int i)
    {
        int max = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] > arr[max])
        max = left;
        if(right < size && arr[right] > arr[max])
        max = right;

        if(max != i)
        {
            swap(arr[i], arr[max]);
            heapify(max);
        }
    }

    void del()
    {
        if(size == 0)
        {
            cout<<"Heap Underflow\n";
            return;
        }

        cout<<arr[0]<<" deleted from the heap"<<endl;

        arr[0] = arr[size-1];
        size--;

        if(size == 0)
        {
            return;
        }

        heapify(0);
    }
};

int main() {
    MaxHeap h(6);
    h.insert(4);
    h.insert(14);
    h.insert(11);

    h.print();
    h.del();
    h.print();
}