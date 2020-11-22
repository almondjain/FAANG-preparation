#include<bits/stdc++.h>
#define n 3
using namespace std;

//Find the longest path in a matrix with given constraints
//18
//DP
/*
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell)
such that all cells along the path are in increasing order with a difference of 1.
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j)
or (i, j-1) with the condition that the adjacent cells have a difference of 1.
*/


int longestFromCell(int i,int j,int mat[n][n],int table[n][n])
{
    //base cases, our index value should not go out of matrix in rws as well as columns
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;
    
    //If this subproblem is already solved
    if(table[i][j]!=-1)
        return table[i][j];
    
    //to store the path lengths in all four directions
    int l=INT_MIN,r=INT_MIN,t=INT_MIN,b=INT_MIN;
    
    //Since all numbers are unique and in range from 1 to n*n, 
    // there is atmost one possible direction from any cell 
    /*      i for rows and j for columns
            i-1,j
    i,j-1    i,j    i,j+1
            i+1,j    
    */
    //moving in right dir
    if(j<n-1 && (mat[i][j]+1)==mat[i][j+1])
        r=1+longestFromCell(i,j+1,mat,table);
    
    //moving in left dir 
    if(j>0 && (mat[i][j]+1)==mat[i][j-1])
        l=1+longestFromCell(i,j-1,mat,table);
    
    //moving in bottom
    if(i<n-1 && (mat[i][j]+1)==mat[i+1][j])
        b=1+longestFromCell(i+1,j,mat,table);
        
    //moving in top
    if(i>0 && (mat[i][j]+1)==mat[i-1][j])
        t=1+longestFromCell(i-1,j,mat,table);
    
    // If none of the adjacent fours is one greater we will take 1 
    // otherwise we will pick maximum from all the four directions 
    table[i][j] = max(r,max(l,max(b,max(t,1))));
    
    return table[i][j];
}


int longestPath(int mat[n][n])
{
    //result-1, cz atleast no. itself i.e. 1 time would be there
    int i,j,result =1;
    
    //table of same size is created
    int table[n][n];
    //all values will be initialised as -1;
    memset(table,-1,sizeof(table));
    
    //longest path beginning from all cells
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //-1 indicates that value need to be filled
            //it will fill value at table[i][j] i.e. longest path from that cell
            if(table[i][j]==-1)
                longestFromCell(i,j,mat,table);
            
            //Update result;
            result=max(result,table[i][j]);
        
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return result;
}


int main()
{
    int mat[n][n] ={{1,2,9},
                    {5,3,8},
                    {4,6,7}};
    
    cout<<"Length of Longest Path is "<<longestPath(mat);

    return 0;
}