// 1. Select any Pivot Element from the array (We select last element of the array)
// 2. Set Pivot Element at its correct position
// 3. Left side
// 4. Right side


// Time Complexity ------

// Best/Avg Case   - TC : Nlogn, SC : logn
// Worst Case      - TC : N2   , SC : N (When the given data is alreday sorted)


#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pos = start;

    for(int i=start; i<= end; i++) {
        if(arr[i] <= arr[end]) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }

    return pos-1;
}

void quickSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

int main() {
    int arr[] = {10,3,4,1,5,6,3,2,11,9};

    quickSort(arr, 0, 9);

    cout<<"Sorted Array : ";
    for(int i=0; i<10; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}