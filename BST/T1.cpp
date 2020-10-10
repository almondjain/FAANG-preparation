#include<bits/stdc++.h>
using namespace std;

//Searchig and Inserting in BST
//T1

struct node
{
    int data;
    node *left,*right;
};

node* getnewnode(int value)
{
    node *root=new node();
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}

node* Insert(node *root,int value)
{
    if(root==NULL)
        return getnewnode(value);
        
    if(value<=root->data)
    {
        root->left=getnewnode(root->left,value);
    }
    else
    {
        root->right=getnewnode(root->right,value);
    }
    return root;
}

//we will return node after searching
node* Search(node *root,int value)
{
    if(root==NULL || root->data==value)
        return root;
    if(value<root->data)
    {
        return Search(root->left,value);
    }
    return Search(root->right,value);
}

int main()
{
    node *root;
    root=Insert(root,50);
    root=Insert(root,20);
    root=Insert(root,40);
    root=Insert(root,70);
    root=Insert(root,60);
    
    root=Search(root,70)
    cout<<root->data;
    
}