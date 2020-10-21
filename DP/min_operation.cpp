#include<bits/stdc++.h>
using namespace std;

//Minimum Operations
//Given a number N. Find the number of operations required to 
//reach N starting from 0. You have 2 operations available:
//Double the number
//Add one to the number
//17

int main()
{
    int n;
    cin>>n;
    int count=0;
    while(n!=0)
    {
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=n-1;
        }
        count++;
    }
    cout<<count;
}