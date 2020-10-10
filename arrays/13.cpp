#include<bits/stdc++.h>
using namespace std;

void majority(int a[],int n)
{
	int i,j;
	//maxcount ,to keep charge of highest no. of occurence of an element
	int count,maxcount=0;
	//index_n,to keep index value of corres maxcount element
	int index_n = -1;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=i;j<n;j++)
		{
			if(a[i]==a[j])
				count += 1;
		}
		if(count > maxcount)
		{
			maxcount = count;
			index_n = i;
		}
	}
	if(maxcount>(n/2))		
		cout<<"Element "<<a[index_n]<<" at index "<<index_n<<" is majority element with "<<maxcount<<" occurences";
	else
		cout<<"No Majority element";

}


int main()
{
	//majority element
	int a[]={1,1,2,2,1};
	int n=sizeof(a)/sizeof(a[0]);

	majority(a,n);

	return 0;
}