// hum kabhi bhi heap se random element del nhi krte hai we always top element and replace by last
// element bcs kyuki har chij ka purpose hota hai like stack,queue 

// insert TC : logn
// delete TC : logn

#include<iostream>
using namespace std;

class MinHeap
{
    int* arr;
    int size; // size of actual heap
    int total_size; // size of the array

    public:
    MinHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int val)  // step up
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

        while(i > 0 && arr[(i-1)/2] > arr[i])
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

    void heapify(int i) // step down
    {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] < arr[smallest])
        smallest = left;
        if(right < size && arr[right] < arr[smallest])
        smallest = right;

        if(smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
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
    MinHeap h(6);
    h.insert(4);
    h.insert(14);
    h.insert(11);

    h.print();
    h.del();
    h.print();
}