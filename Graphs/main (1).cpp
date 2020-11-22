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


bool WordBreak(string input)
{
    int n=input.size();
    //Base case
    if(n==0)
        return true;
    int i;
    for(i=1;i<=n;i++)
    {
        if(IsFound(input.substr(0,i))&& WordBreak(input.substr(i,n-i)));
            return true;
    }
    return false;
}

int main()
{
    //given a dictionary of words and input string, we have to find out 
    //whether the seperated string present in dict or not
    
    
    string input = "ijjlikeabc";
    
    if(WordBreak(input))
        cout<<"true";
    else
        cout<<"false";
    
    return 0;
}