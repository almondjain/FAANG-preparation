#include<bits/stdc++.h>
using namespace std;

int search_pos(int a[],int n,int key)
{
	int i,pos=-1;
	for(i=0;i<n;i++)
		if(a[i]==key)
			 pos = i;
			 
	
	return pos;
}

int main()
{
	

	//Search in Unsorted array

	int a[] = {5,2,8,6,9,1};
	int n = sizeof(a)/sizeof(a[0]);

	int key = 8;
	int pos;
	pos = search_pos(a,n,key);

	if(pos!=-1)
		cout<<"Element "<<key<<" found at position "<<pos;
	else
		cout<<"Element not found";

	return 0;

}