// Divide and Conquer

// Time Complexity ------

// Best/Avg/Worst Case   - TC : Nlogn, SC : logn

#include<iostream>
#include<vector>
using namespace std;

void mergeArray(int arr[], int start, int mid, int end) {
    vector<int> temp(end-start+1);
    int left = start;
    int right = mid+1;
    int index = 0;

    while(left <= mid && right <= end) {
        if(arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
            index++;
        }
        else {
            temp[index] = arr[right];
            right++;
            index++;
        }
    }

    // left array is not empty completely
    while(left <= mid) {
        temp[index] = arr[left];
        left++;
        index++;
    }

    // right array is not empty completely
    while(right <= end) {
        temp[index] = arr[right];
        right++;
        index++;
    }

    index = 0;

    // copy temp array elements into actual array
    while(start <= end) {
        arr[start] = temp[index];
        start++;
        index++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if(start == end) {
        return;
    }

    int mid = start+(end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    mergeArray(arr, start, mid, end);
}

int main() {
    int arr[] = {6, 3, 1, 2, 8, 9, 10, 7, 3, 10};
    mergeSort(arr,0,9);

    cout<<"Sorted Array : ";
    for(int i=0; i<10; i++) {
        cout<<arr[i]<<" ";
    }
}