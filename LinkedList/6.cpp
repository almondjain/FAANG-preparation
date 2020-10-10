#include<bits/stdc++.h>
using namespace std;

//nth node from the end

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
    //when idx and count matches, we got our result
    int idx = size-k+1;
    int count=0;
    while(n!=NULL)
    {
        count++;
        if(count==idx)
        {
            cout<<n->data;
            break;
        }
        n=n->next;
    }
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
    fifth->next=sixth;
    
    sixth->data = 6;
    sixth->next=NULL;

    
    int size = find_size(head);
    find_node(head,k,size);
    
}