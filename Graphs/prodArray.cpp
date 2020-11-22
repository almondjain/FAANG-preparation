#include<bits/stdc++.h>
using namespace std;

//A Product Array Puzzle
/*
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal
to the product of all the elements of arr[] except arr[i]. Solve it without division operator in O(n) time.
*/

int main()
{
    int arr[]={10,3,5,6,2};
    int i,n=sizeof(arr)/sizeof(arr[0]);
    int prod=1;
    
    //find prod of all, first
    for(i=0;i<n;i++)
    {
        prod*=arr[i];
    }
    
    //storing results in same arr
    for(i=0;i<n;i++)
    {
        arr[i] = int(prod*pow(arr[i],-1));
    }
    
    //printing elements
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}