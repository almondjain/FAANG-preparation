#include<bits/stdc++.h>
using namespace std;

//Word break Problem
//13-DP
//doubt

bool IsFound(string input,int dict[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(dict[i].compare(input)==0)
            return false;
    }
    return true;
}


bool WordBreak(string input,int dict[],int n)
{
    //Base case
    if(n==0)
        return true;
    
    for(int i=1;i<=n;i++)
    {
        if(IsFound(substr(0,i),dict,n)&& WordBreak(input.substr(i,n-i),dict,n))
            return true;
    }
    return false;
}

int main()
{
    //given a dictionary of words and input string, we have to find out 
    //whether the seperated string present in dict or not
    
    int dict[]={i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango};
    int n=sizeof(dict)/sizeof(dict[0]);
    
    string input = "ilike";
    
    if(WordBreak(input,dict,n)==1)
        return true;
    else
        return false;
    
    return 0;
}