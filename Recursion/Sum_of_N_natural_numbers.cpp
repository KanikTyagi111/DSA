#include<iostream>
using namespace std;

int Sum(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return n + Sum(n-1);
}

int main() 
{   int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"Sum of "<<n<<" natural numbers is : ";
    cout<<Sum(n);

    return 0;
}