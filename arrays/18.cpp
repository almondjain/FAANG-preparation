#include<bits/stdc++.h>
using namespace std;

//18

// Given an array of integers nums and an integer target,
//return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
// You can return the answer in any order.

void printpair(int a[],int n,int target)
{
    set<int> s;
    int i=0;
    
    for(i=0;i<n;i++)
    {
        int temp = target-a[i];
        if(s.find(temp)!=s.end())
        {
            cout<<"Pair is "<<a[i]<<" "<<temp<<endl;
        }
        s.insert(a[i]);
    }
}

int main()
{
	//Here we will use the concept of set

	int a[]={0,-1,2,-3,-1,1};
	int target = -2;
	int n = sizeof(a)/sizeof(a[0]);
	
	printpair(a,n,target);
	return 0;
}