#include<bits/stdc++.h>
using namespace std;

//finding a Binomial coefficient using recursion and dp 
//2
//find C(n,k) = nCk
//C(n,k) = C(n-1,k-1)+C(n-1,k)
//C(n,0)=C(n,n)=1

int BinoCoeffRec(int n,int k)
{
    if(k==0 || k==n)
        return 1;
    
    return(BinoCoeffRec(n-1,k)+BinoCoeffRec(n-1,k-1));
    
}

int BinoCoeffDP(int n,int k)
{
    int C[n+1][k+1];
    int i,j;
    //here we need two variables and two loops bcz our 2 values are changing i.e. n and k
    //we will store each combination of n and k in C[][]
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            //min(i,k)- i will tell range when n is less than k bcz we cant have (0,2)or(1,4) ,here k needs to be equal or less than n
            //k will tell when n is high bcz no need to find (4,4),(4,3) , there would be no use of them when k itself is 2
            
            //Base cases
            if(j==0 || j==i)
                C[i][j]=1;
            else
            {
                C[i][j]=C[i-1][j]+C[i-1][j-1];
            }
        }
    }
    //till now we found our C[n][k] by Bottom up approach,we just store all previous values
    
    return C[n][k];
}

int main()
{
    int n=4,k=2;
    cout<<"Binomial coefficient for C("<<n<<" ,"<<k<<") is "<<BinoCoeffDP(n,k)<<endl;
    return 0;
}
