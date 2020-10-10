#include<bits/stdc++.h>
using namespace std;

//middle of linked list
//first approach

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

void find_mid(struct node *n,int size)
{
    int mid;
    //when idx and count matches, we got our result
    if(size%2==0)
        mid= (size/2)+1;
    else
        mid = (size/2)+1;
    int count=0;
    while(n!=NULL)
    {
        count++;
        if(count==mid)
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
    find_mid(head,size);
    
}