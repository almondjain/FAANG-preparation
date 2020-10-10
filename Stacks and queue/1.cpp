#include<bits/stdc++.h>
using namespace std;

//Implementation of stack and its operations
//1

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main()
{
    stack<int>s;
    
    cout<<s.empty()<<endl;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    s.push(3);
    cout<<s.empty()<<endl;
    s.push(4);
    cout<<s.top()<<endl;
    s.push(5);
    cout<<s.size()<<endl;
    
    print(s);
    
    return 0;
    
}