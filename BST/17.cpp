#include<bits/stdc++.h>
using namespace std;

//Print Right view of a binary tree
//17
//Recursive approach

struct node
{
    int data;
    node *left, *right;
};

node* getnewnode(int value)
{
    node *root=new node();
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}

void rightTree(node *root,int level,int *max_level)
{
    if(root==NULL)
        return;
    
    //here *max_level means value at address maxlevel
    
    if(*max_level<level)
    {
        cout<<root->data<<" ";
        *max_level=level;
    }
    
    //here max_level itself have a address data type,so need not to pass it as &--
    rightTree(root->right,level+1,max_level);
    rightTree(root->left,level+1,max_level);
}

void rightview(node *root)
{
    int max_level=0;
    int level=1;
    rightTree(root,level,&max_level);
}

int main()
{
    node *root=getnewnode(12);
    root->left=getnewnode(10);
    root->right=getnewnode(30);
    root->right->left=getnewnode(20);
    root->right->right=getnewnode(40);
    
    rightview(root);
    
    return 0;
}