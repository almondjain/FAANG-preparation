#include<bits/stdc++.h>
using namespace std;

//Coin Change using recursion and DP
//3
//return count no. of ways  we can build sum n with various m coins

//recursion
int countRec(int arr[],int m,int sum)
{
    if(sum<0)
        return 0;
        
    if(sum==0)
        return 1;
    
    if(m<=0 && sum>0)
        return 0;
        
    return(countRec(arr,m-1,sum)+countRec(arr,m,sum-arr[m-1]));
    
}

//DP
int countDP(int arr[],int m,int sum)
{
    //sum .ie n+1 is no of rows,(base case 0 also included)
    //no. of coins - m- columns
    int table[sum+1][m];
    int i,j,x,y;
    
    //fill the entries for sum=0, 1 way(to not choose any coin) no matter no of coins given
    for(i=0;i<m;i++)
    {
        table[0][i]=1;
    }
    
    //Fill rest of table with bottom up approach
    for(i=1;i<=sum;i++)
    {
        for(j=0;j<m;j++)
        {
            //Count of solutions including arr[j] i.e mth coin
            //checking that calculated sum doesnot go below 0, if go then return 0
            x = ((i-arr[j])>=0)? table[i-arr[j]][j]:0;
            //Count of solutions excluding arr[j] i.e mth Coin
            //checking that there are some no. of coins if no coins are there than return 0
            y = (j>=1)? table[i][j-1]:0;
            
            table[i][j]=x+y;
        }
    }
    
    //as indexing is from 0, so for given m, our value will be at m-1;
    return table[sum][m-1];
    
}

int main()
{
    //arr is always sorted, make sure
    int arr[]={1,2,3};
    int m=sizeof(arr)/sizeof(arr[0]);
    int i,j;
    int sum=4;
    
    /*
    n=4;
    arr=[1,2,3]
    o/p=4
    [1,1,1,1]
    [1,1,2]
    [2,2]
    [3,1]
    */
    cout<<countRec(arr,m,sum);
    
    return 0;
}