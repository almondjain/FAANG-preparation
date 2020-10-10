#include<bits/stdc++.h>
using namespace std;

// delete a node at nth position
//13

struct node 
{
    int data;
    struct node *next;
};

void print(struct node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}

struct node* delete_node(struct node *head,int n)
{
    struct node *curr,*prev;
    curr = head;
    
    if(n==1)
    {
        head=curr->next;
    }
    else
    {
        for(int i=0;i<n-2;i++)
        {
            curr=curr->next;
        }
        prev=curr;
        curr=curr->next;
        prev->next=curr->next;
    }
    return head;
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
    fourth->next=fifth;
    
    fifth->data=5;
    fifth->next=NULL;
    
    cout<<"Linked List before deletion"<<endl;
    print(head);
    
    int del_n = 1;
    
    head=delete_node(head,del_n);
    
    cout<<"Linked List after deletion"<<endl;
    print(head);
}
