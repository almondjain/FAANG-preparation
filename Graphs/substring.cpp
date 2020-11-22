#include<bits/stdc++.h>
using namespace std;

//substrings of a string

int main()
{
    string s="abbcd";
    int n=s.size();
    int i,j;
    string temp;
    vector<string> v; 
    
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            temp=s.substr(i,j);
            v.push_back(temp);
        }
    }
    
    //printing all the substrings
    n=v.size();
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }
}