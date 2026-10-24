#include<iostream>
using namespace std;

void targetSum(int arr[], int index, int n, int target,int last_val, int& count) {
    if(target == 0) {
        count++;
        return;
    }
    if(index == n || target < 0) {
        return;
    }

   targetSum(arr,index+1,n,target,last_val, count);
   if(arr[index] > last_val)
   targetSum(arr,index+1,n,target-arr[index],arr[index], count);
}

int main() {
    int arr[] = {2,5,1,6,8,4,9};
    int target = 15;
    int count = 0;
    targetSum(arr,0,7,target,-1,count);

    cout<<count<<endl;
}