#include<bits/stdc++.h>
using namespace std;

//nth node of linked list
//accesing linked list by index value


class node
{
    public:
        int data;
        node* next;
        
};

void find(node *n,int idx)
{
    int count = 0;
    while(n!=NULL)
    {
        if(count==idx)
        {
            cout<<"Index: "<<idx<<" , "<<"Element "<<n->data;
            break;
            
        }
        else
        {
            count++;
            n=n->next;
        }
    }
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
    
    int idx = 2;
    
    find(head,idx);
    
    return 0;
}