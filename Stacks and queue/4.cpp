#include<bits/stdc++.h>
using namespace std;

//Reverse a String using stack
//4

string reverse_string(string x)
{
    stack<char> s;
    int i,n=x.size();
    for(i=0;i<n;i++)
    {
        s.push(x[i]);
    }
    for(i=0;i<n;i++)
    {
        x[i]=s.top();
        s.pop();
    }
    return x;
}

int main()
{
    string x = "abcd";
    cout<<"Before Reversing"<<endl;
    cout<<x<<endl;
    cout<<"After Reversing"<<endl;
    x = reverse_string(x);
    cout<<x;
}