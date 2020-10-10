#include<bits/stdc++.h>
using namespace std;

//Reversing a linked list using recursive method
//12
//not working

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

struct node* reverse_l(struct node *p)
{
    struct node *head;
    if(head->next == NULL)
    {
        head=p;
        return head;
    }
    reverse_l(p->next);
    struct node *q= p->next;
    q->next=p;
    p->next=NULL;
    
}

int main()
{
    struct node *head,*sec, *third, *fourth, *fifth, *sixth;
    
    head = new node();
    sec = new node();
    third = new node();
    fourth = new node();
    fifth = new node();
    sixth = new node();
    
    head->data=1;
    head->next=sec;
    
    sec->data=2;
    sec->next=third;
    
    third->data=3;
    third->next=fourth;
    
    fourth->data=4;
    fourth->next=fifth;
    
    fifth->data=5;
    fifth->next=sixth;
    
    sixth->data=6;
    sixth->next=NULL;
    
    cout<<"Liked List efore reversing"<<endl;
    print(head);
    
    head = reverse_l(head);
    
    //printing of linked list
    cout<<"Linked List after reversing"<<endl;
    print(head);
    
    return 0;
    
}