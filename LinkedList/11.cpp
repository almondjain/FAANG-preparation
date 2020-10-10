#include<bits/stdc++.h>
using namespace std;

//Reversing a linked list using iteration method
//11

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

struct node* reverse_l(struct node *head)
{
    struct node *current,*prev,*next;
    current = head;
    prev=NULL;
    next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
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