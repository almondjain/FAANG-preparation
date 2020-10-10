#include<bits/stdc++.h>
using namespace std;

//Generate a Balanced BST using sorted array elements
//T2

struct node
{
    int data;
    node *left;
    node *right;
};

node* getnewnode(int value)
{
    node *root=new node();
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}

//if we draw our bst right, then after doing its inorder traversal our output array should e sorted one
//so to check lets make an inorder fnx
void Inorder(node *root)
{
    if(root==NULL)
        return;
        
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


node* arraytoBST(int a[],int l,int h)
{
    if(l>h)
        return NULL;
    int mid=(l+h)/2;
    node *root= getnewnode(a[mid]);

    root->left=arraytoBST(a,l,mid-1);
    root->right=arraytoBST(a,mid+1,h);

    return root;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,45,89,99};
    int n=sizeof(a)/sizeof(a[0]);
    
    node *root=arraytoBST(a,0,n);
    Inorder(root);
    
}