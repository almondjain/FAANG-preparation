#include<bits/stdc++.h>
using namespace std;

//Balancing of Symbols
//5

//allowed brackets are only - (),{},[]

bool Paranthesis(string str)
{
    stack<char> s;
    char x;
    int i=0;
    int n=str.length();
    
    //Iterate
    for(i=0;i<n;i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            //Push the opening bracket in stack
            s.push(str[i]);
            continue;
        }
        
        //IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
    
        if(s.empty())
            return false;
        
        //Compare type of brackets using switch command
    
        switch(str[i])
        {
            case ')':
            {
                x=s.top();
                s.pop();
                if(x=='{' || x=='[')
                    return false;
                break;
            }
            case '}':
            {
                x=s.top();
                s.pop();
                if(x=='(' || x=='[')
                    return false;
                break;
            }
            case ']':
            {
                x=s.top();
                s.pop();
                if(x=='(' || x=='{')
                    return false;
                break;
            }
        }
    }
    //Check empty stack
    return s.empty();
}

int main()
{
    string expr = "{()}[]"; 
  
    if (Paranthesis(expr)) 
        cout<<"Balanced"; 
    else
        cout<<"Not Balanced"; 
    return 0; 
}