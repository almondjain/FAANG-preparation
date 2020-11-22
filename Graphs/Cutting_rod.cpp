#include<bits/stdc++.h>
using namespace std;

//cutting rod problem
//12

int CutRodRec(int price[],int n)
{
    if(n<=0)
        return 0;
    
    int max_value=INT_MIN;
    
    //Recursively cut the rod in different pieces and compare different 
   // configurations
   for(int i=0;i<n;i++)
   {
       max_value=max(max_value,price[i]+CutRodRec(price,n-i-1));
   }
   
   return max_value;
}

int CutRodDP(int price[],int n)
{
    int val[n+1];
    val[0]=0;
    int i,j;
    
    //Build the table val[] in bottom up manner and return the last entry
   //from the table
   for (i=1;i<=n;i++)
   {
       int max_val=INT_MIN;
       for (j=0;j<i;j++)
         max_val=max(max_val,price[j] + val[i-j-1]);
       val[i]=max_val;
   }
 
   return val[n];
}

int main()
{
    int price[]={1,5,8,9,10,17,17,20};
    //n is length of rod
    int n=sizeof(price)/sizeof(price[0]);
    
    cout<<CutRodDP(price,n);
    return 0;
}