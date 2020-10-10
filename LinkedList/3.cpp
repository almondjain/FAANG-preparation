#include<bits/stdc++.h>
using namespace std;

//number of elements in linked list
//Recursive approach

class node
{
    public:
        int data;
        node* next;
        
};

bool search(node *n,int key)
{
    while(n!=NULL)
    {
        if(n->data==key)
            return true;
        else
            n=n->next;
    }
    return false;
}

int main()
{
    node* head = NULL;
    node* sec = NULL;
    node* third = NULL;
    
    head = new node();
    sec = new node();
    third = new node();
    
    head->data=1;
    head->next=sec;
    
    sec->data=2;
    sec->next=third;
    
    third->data=3;
    third->next=NULL;
    
    int key = 4;
    
    cout<<search(head,key);
    
    return 0;
}