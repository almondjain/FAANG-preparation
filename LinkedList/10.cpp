#include<bits/stdc++.h>
using namespace std;

//Finding a loop in Linked list
//we will use set here

struct node
{
    int data;
    struct node *next;
};

bool findloop(struct node *n)
{
    set<struct node*> s;
    while(n!=NULL)
    {
        if(s.find(n)!=s.end())
            return true;
        
        s.insert(n);
        n=n->next;
    }
    return false;
}

int main()
{
    struct node *head,*sec,*third,*fourth,*fifth;
    
    head=new node();
    sec=new node();
    third=new node();
    fourth=new node();
    fifth=new node();
    
    head->data=1;
    head->next=sec;
    
    sec->data=2;
    sec->next=third;
    
    third->data=3;
    third->next=fourth;
    
    fourth->data=4;
    fourth->next=sec;
    
    fifth->data=5;
    fifth->next=NULL;
    
    bool res;
    res = findloop(head);
    cout<<res;
    
}