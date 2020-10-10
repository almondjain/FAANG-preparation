#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1,2,3,1,3,5,6,1,7};
	int n = sizeof(a)/sizeof(a[0]);

	map<int,int> m;

	for(int i=0;i<n;i++)
		m[a[i]]++;

	for(auto k:m)
		cout<<k.first<<" "<<k.second<<endl;
	return 0;
}