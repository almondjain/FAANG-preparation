#include<bits/stdc++.h>
using namespace std;

//Word break Problem
//13-DP
//doubbt

bool IsFound(string input)
{
    string dict[]={"i", "like", "sam", "sung", "samsung", "mobile", "ice, cream", "icecream", "man", "go", "mango"};
    int size=sizeof(dict)/sizeof(dict[0]);
    
    for(int i=0;i<size;i++)
        if(dict[i].compare(input)==0)
            return true;
            
    return false;
}


bool WordBreakRec(string input)
{
    int n=input.size();
    //Base case
    if(n==0)
        return true;
    int i;
    for(i=1;i<=n;i++)
    {
        if(IsFound(input.substr(0,i))&& WordBreakRec(input.substr(i,n-i)));
            return true;
    }
    return false;
}

bool WordBreakDP(string input)
{
    int n = input.size();
    
    if(n==0)
        return true;
    
    bool arr[n+1]={false};
    
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==false && IsFound(input.substr(0,i)));
            arr[i]=true;
            
        if(arr[i]==true)
        {
            if(i==n)
                return true;
            
            for(int j=i+1;j<=n;j++)
            {
                if(arr[j]==false && IsFound(input.substr(i,j-i)));
                    arr[j]=true;
                
                if(j==n && arr[j]==true)
                    return true;
                
            }
        }
    }
}

int main()
{
    //given a dictionary of words and input string, we have to find out 
    //whether the seperated string present in dict or not
    
    string input = "ijjlikeabc";
    
    if(WordBreakDP(input))
        cout<<"true";
    else
        cout<<"false";
    
    return 0;
}