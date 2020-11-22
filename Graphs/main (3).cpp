#include<bits/stdc++.h>
using namespace std;

//Longest Common Prefix

string LCPutil(string s1,string s2)
{
    int n1=s1.size();
    int n2=s2.size();
    
    int n=min(n1,n2);
    
    string res;
    
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
            break;
        
        res.push_back(s1[i]);
    }
    
    return res;
}

string LCP(int arr[],int n)
{
    string prefix = arr[0];
    
    for(int i=1;i<n;i++)
    {
        prefix = LCPutil(prefix,arr[i]);
    }
    
    return prefix;
}

int main()
{
    string arr[]={"flower","flow","flight"};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<arr[0]<<" "<<typeid(arr[0]).name()<<endl;
    cout<<arr[1]<<" "<<typeid(arr[1]).name()<<endl;
    cout<<arr[2]<<" "<<typeid(arr[2]).name()<<endl;
    
    //string ans=LCP(arr,n);
    
    //cout<<ans;
}