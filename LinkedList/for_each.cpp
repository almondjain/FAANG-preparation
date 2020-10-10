#include<bits/stdc++.h>
using namespace std;

//Implementation of for_each loop

void factor2(int x)
{
    cout<<x*2<<" ";
}
int main()
{
    int a[]={1,2,3,4,5};
    
    for_each(a,a+5,factor2);
    return 0;
}