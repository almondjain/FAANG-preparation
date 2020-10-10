#include<bits/stdc++.h>
using namespace std;

//Implementation of stack using arrays
//without stl
//2

class Stack
{
    //to keep account of no. of elements added in stack
    int n;
    //here a will worked as a stack where its max size is 10
    int a[10];
    public:
    //costructor
    Stack()
    {
        //initialise every oject top as -1
        n=-1;
    }
    void push(int x);
    void pop();
    bool empty();
    int top();
    int size();
    void print();
};

void Stack::push(int x)
{
    if(n>(10-1))
        cout<<"Overflow: cant added, Stack is full"<<endl;
    else
        a[++n]=x;
}

void Stack::pop()
{
    if(n<0)
        cout<<"Underflow: No element in the stack"<<endl;
    else
        n--;
}

bool Stack::empty()
{
    if(n<0)
        return true;
    else
        return false;
}

int Stack::top()
{
    return a[n];
}

int Stack::size()
{
    return n+1;
}

void Stack::print()
{
    for(int i=0;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Stack s;
    cout<<s.empty()<<endl;
    s.pop();
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    cout<<s.top()<<endl;
    s.push(3);
    s.print();
    s.push(4);
    s.print();
    cout<<s.top()<<endl;
    s.push(5);
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    s.print();
    s.pop();
    s.push(6);
    s.print();
    s.push(7);
    s.print();
    s.push(8);
    s.print();
    s.push(9);
    s.print();
    s.push(10);
    s.print();
    s.push(11);
    s.print();
    s.push(12);
    s.print();
    s.push(13);
    
    
    return 0;
}