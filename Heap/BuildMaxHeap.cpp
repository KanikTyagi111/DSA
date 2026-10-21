// build max heap TC : n

#include<iostream>
using namespace std;

void heapify(int arr[],int index, int n) {
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right<n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(arr[index],arr[largest]);
        heapify(arr,largest,n);
    }
}

void buildMaxHeap(int arr[],int n) {
    // step down
    for(int i=n/2-1; i>=0; i--) {
        heapify(arr,i,n);
    }
}

void print(int arr[],int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    buildMaxHeap(arr,10);
    print(arr,10);
}