#include<bits/stdc++.h>
using namespace std;

void majority(int a[],int n)
{
	map<int,int> m;
	int i;

	//storing element and its frequency in map m as a key value pair

	for(i=0;i<n;i++)
		m[a[i]]++;

	//accesing each item i.e key value pair of map and check for condition

	for(auto k:m)
	{
		if(k.second>n/2)
			cout<<"Majority element is "<<k.first<<" with "<<k.second<<" frequency";
	}
}


int main()
{
	//Most optimised way for finding majority element

	int a[]={1,2,3,1,2,1,1};
	int n = sizeof(a)/sizeof(a[0]);

	majority(a,n);
	return 0;
}