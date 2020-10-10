#include <bits/stdc++.h>
using namespace std;

//Given an array nums, write a function to move all 0's 
//to the end of it while maintaining the relative order 
//of the non-zero elements.

int shift(int a[],int n,int pos)
{
    int i,temp = a[pos];
    for(i=pos;i<n-1;i++)
    a[i]=a[i+1];
    
    a[n-1]=temp;
    
}


int main()
{
    int a[]={0,1,0,3,12};
    int n=sizeof(a)/sizeof(a[0]);
    
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        shift(a,n,i);
    }
    
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
}