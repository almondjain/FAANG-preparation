#include<bits/stdc++.h>
using namespace std;

//Subset sum problem
//7


//By Recursion
bool SubsetsumRec(int a[],int n,int sum)
{
    //Base Cases
    if(sum==0)
        return true;
    
    if(n==0)
        return false;
        
    //ignore last element if it is greater than target sum
    if(a[n-1]>sum)
        return SubsetsumRec(a,n-1,sum);
    
    //excluding last element or including last element
    return SubsetsumRec(a,n-1,sum) || SubsetsumRec(a,n-1,sum-a[n-1]);
    
}

//By DP
bool SubsetsumDP(int a[],int n,int sum)
{
    bool table[n+1][sum+1];
    int i,j;
    //Base Cases
    //if sum is 0 thn all cases are TRUE
    for(i=0;i<n+1;i++)
    {
        table[i][0]=true;
    }
    
    //if sum is not zero and no elements are there thn false
    for(j=1;j<sum+1;j++)
    {
        table[0][j]=false;
    }
    
    //Fill the subset table in bottom up manner
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(j<a[i-1])
                table[i][j]=table[i-1][j];
                //table[i][j]=false;
            if(j>=a[i-1])
                table[i][j]= table[i-1][j]||table[i-1][j-a[i-1]];
        }
    }
    
    return table[n][sum];
}


int main()
{
    int a[]={3, 34, 4, 12, 5, 2};
    int sum=90;
    int n=sizeof(a)/sizeof(a[0]);
    
    bool res = SubsetsumDP(a,n,sum);
    
    if(res==1)
        cout<<"TRUE";
    else
        cout<<"FALSE";
}