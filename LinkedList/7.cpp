#include<bits/stdc++.h>
using namespace std;

//nth node from the end
//second approach

struct node
{
    public:
        int data;
        struct node *next;
    
};

int find_size(struct node *n)
{
    //finding no. of elements in linked list
    int size = 0;
    while(n!=NULL)
    {
        size++;
        n=n->next;
    }
    return size;
}

void find_node(struct node *n,int k,int size)
{
    //finding index i.e. nth node from the end
    struct node *p;
    struct node *q;
    
    p=new node();
    q=new node();
    
    q=n;
    p=n;
    
    while(p!=NULL)
    {
        for(int i=0;i<k;i++)
        {
            p=p->next;
        }
        q=q->next;
    }
    if(size%2==0)
        q=q->next;
    
    cout<<q->data;
}

int main()
{
    int k =2;
    struct node *head=NULL;
    struct node *sec = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;
    struct node *sixth = NULL;
    
    head = new node();
    sec = new node();
    third = new node();
    fourth = new node();
    fifth = new node();
    sixth = new node();
    
    head->data = 1;
    head->next = sec;
    
    sec->data = 2;
    sec->next = third;
    
    third->data = 3;
    third->next=fourth;
    
    fourth->data = 4;
    fourth->next = fifth;
    
    fifth->data = 5;
    fifth->next=NULL;
    
    sixth->data = 6;
    sixth->next=NULL;

    
    int size = find_size(head);
    find_node(head,k,size);
    
}