#include<bits/stdc++.h>
using namespace std;

//Partition Problem
//8
//we have to return true or false if we found 2 same sized array

//recursion
bool FindPartitionUtil(int a[],int n,int sum)
{
    //Base Cases
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;
        
    //ignore if last element is greater than target sum
    if(a[n-1]>sum)
        return FindPartitionUtil(a,n-1,sum);
    
    return FindPartitionUtil(a,n-1,sum)||FindPartitionUtil(a,n-1,sum-a[n-1]);
}

bool FindPartition(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    
    //checking odd or even
    if((sum%2)!=0)
        return false;
    else
        return FindPartitionUtil(a,n,sum/2);
}

//DP
bool FindPartitionDP(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    
    if((sum%2)!=0)
        return false;
    
    bool table[(sum/2)+1][n+1];
    int i,j;
    
    //initialise top row as true , as when sum of elements is 0 then it is true
    for(i=0;i<=n;i++)
    {
        table[0][i]=true;
    }
    
    //initialise left most column except table[0][0] as false
    //when there is no element but we have sum
    for(i=1;i<=(sum/2);i++)
    {
        table[i][0]=true;
    }
    
    //Fill the partition table in bottom up manner
    for(i=1;i<= sum/2;i++) {
        for(j=1; j<=n; j++) {
            table[i][j] = table[i][j - 1];
            if(i>=a[j - 1])
                table[i][j]=table[i][j] || table[i - a[j - 1]][j - 1];
        }
    }
    
    return table[sum/2][n];
}

int main()
{
    int a[]={2,3,5};
    int n=sizeof(a)/sizeof(a[0]);
    
    if(FindPartitionDP(a,n)==true)
        cout<<"Partitioned array is possible"<<endl;
    else
        cout<<"Not Possible"<<endl;
}