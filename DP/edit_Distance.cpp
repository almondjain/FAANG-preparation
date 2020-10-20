#include<bits/stdc++.h>
using namespace std;

//Edit Distance
//make sure that we are just calculating the cost of given 3 operation not actually applying those
//DP
//15

int min(int a, int b, int c)
{
    return min(min(a,b),c);
}

//Recursion
int editDistanceRec(string str1,string str2,int m,int n)
{
    //Base Cases
    //if str1 is empty,insert all char of str2 in str1
    if(m==0)
        return n;
    
    //if str2 is empty, remove all elements of str1;
    if(n==0)
        return m;
    
    //start traversing from back
    //if both char are same, thn ignore and just move to check next elements
    if(str1[m-1]==str2[n-1])
        return editDistanceRec(str1,str2,m-1,n-1);
    
    //if they are not equal thn apply all three operations and check which one comes with min. cost
    //add 1 for current operation,as they are not equal so we apply all 3 op on that as well and thn recur for rest
    
    return 1+ min(editDistanceRec(str1,str2,m,n-1), //Insert
                editDistanceRec(str1,str2,m-1,n), //Remove
                editDistanceRec(str1,str2,m-1,n-1) //Replace
                ); 

}

//DP
int editDistanceDP(string str1,string str2,int m, int n)
{
    //create a table to store results of subproblems
    int table[m+1][n+1];
    
    //fill table in bottom up manner
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //if first string is empty
            //insert all char of second string
            if(i==0)
                table[i][j]=j;
            
            //if second string is empty
            //remove all the elements from first string
            else if(j==0)
                table[i][j]=i;
            
            //if char do match thn recur for next i.e n-1 th string
            else if(str1[i-1]==str2[j-1])
                table[i][j]=table[i-1][j-1];
            
            else
                table[i][j]= 1+ min(table[i][j-1],//insert
                        table[i-1][j],//remove
                        table[i-1][j-1]//replace
                    );
                    
            //cout<<table[i][j]<<" ";
        }
        //cout<<endl;
    }
    return table[m][n];
}

int main()
{
    string str1="cut";
    string str2="cat";
    
    cout<<editDistanceDP(str1,str2,str1.size(),str2.size());

    return 0;
}