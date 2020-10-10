#include <bits/stdc++.h>
using namespace std;

//reverse an array

int reverse_arr(int a[],int n)
{
    int l=0,h=n-1;
    while(l<h)
    {
        int temp = a[l];
        a[l] = a[h];
        a[h] = temp;
        l++;
        h--;
    }
}


int main()
{
    int a[]={1,2,3,4,5,6};
    int i,n = sizeof(a)/sizeof(a[0]);
    
    cout<<"Before reversing"<<endl;
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    
    reverse_arr(a,n);
    
    cout<<endl<<"After reversing"<<endl;
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    
    return 0;
}