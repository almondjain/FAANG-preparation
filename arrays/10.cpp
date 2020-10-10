#include<bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer target,
//return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
// You can return the answer in any order.


int main()
{
    int a[]={0,-1,2,-3,-1,1};
    int target = -2;
    int n = sizeof(a)/sizeof(a[0]);
    int j,i=0;
    while(i<n)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==target-a[j])
            cout<<i<<" "<<j<<endl;
        }
        i++;
    }
}
 

