#include<bits/stdc++.h>
using namespace std;

//construct a complete binary tree from given array in level order traversal
//20
//root-i, root->left = 2i+1, root->right= 2i+2

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

node* arrayToBinary(int a[],node *root,int i,int n)
{
    if(i<n)
    {
        node *temp=getnewnode(a[i]);
        root=temp;
        
        //insert left child
        root->left=arrayToBinary(a,root->left,2*i+1,n);
        
        //insert right child
        root->right=arrayToBinary(a,root->right,2*i+2,n);
    }
    
    return root;
}

void Inorder(node *root)
{
    if(root==NULL)
        return;
        
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    node *root;
    root=arrayToBinary(a,root,0,n);
    //to check tree is constructed or not, lets check through innorder
    Inorder(root);
    
 
}