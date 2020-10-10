#include<bits/stdc++.h>
using namespace std;

void majority(int a[],int n)
{
	int i,count=0;
	//for keeping maximum count
	int maxcount = 0;
	//for keeping corres index value
	int index_v = -1;
	//for comaprison with each element
	int temp=a[0];
	for(i=0;i<n;i++)
		if(temp==a[i])
		{
			count += 1;
			//keeping maxcount and index value
			if(count>maxcount)
			{
				maxcount = count;
				index_v = i;
			}
		}
		else
		{
			temp=a[i];
			count = 1;
		}

	//checking up the condition
	if(maxcount>(n/2))
		cout<<"Element "<<a[index_v]<<" is majority element with "<<maxcount<<" occurences"<<endl;
	else
		cout<<"No Majority element found"<<endl;
}

int main()
{
	int a[] = {1,2,3,2,2,1,2};
	int n = sizeof(a)/sizeof(a[0]);

	//sorting of an array
	sort(a,a+n);

	majority(a,n);

	return 0;
}
