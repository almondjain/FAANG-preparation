#include<bits/stdc++.h>
using namespace std;

//Implementation of stacks using linked list
//3

struct node
{
    int data;
    struct node *next;
};

class Stack
{
    struct node *head=NULL;
    
    
    public:
    void push(int a)
    {
        //no need to check overflow condition
        struct node *temp = new node();
        temp->data = a;
        temp->next = head;
        head=temp;
    }
    
    void pop()
    {
        struct node *temp;
        //checking underflow condition
        if(head==NULL)
            cout<<"Underflow: Array is empty"<<endl;
        else
        {
            temp=head;
            head = temp->next;
            delete(temp);
        }
    }
    
    void print()
    {
        struct node *temp;
        temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    bool empty()
    {
        if(head==NULL)
            return true;
        else
            return false;
    }
    
    int size()
    {
        int count=0;
        struct node *temp;
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    
};

int main()
{
    Stack s;
    cout<<s.empty()<<endl;
    s.print();
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    s.print();
    s.pop();
    cout<<s.size()<<endl;
    s.print();
    s.pop();
    cout<<s.size()<<endl;
    s.print();
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}