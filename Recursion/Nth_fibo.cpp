#include<iostream>
using namespace std;

int fibo(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }

    return fibo(n-1) + fibo(n-2);
}

int main() {
    int n = 6;

    cout<<n<<"th term in fibonacci : ";
    cout<<fibo(n);

    return 0;
}