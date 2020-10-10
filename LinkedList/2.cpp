#include<bits/stdc++.h>
using namespace std;

//number of elements in linked list
//Iterartive approach

class node
{
    public:
        int data;
        node* next;
        
};

int print(node *n)
{
    int count = 0;
    while(n!=NULL)
    {
        count++;
        n=n->next;
    }
    return count;
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
    
    cout<<print(head);
}