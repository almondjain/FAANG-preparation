#include<bits/stdc++.h>
using namespace std;

//find a pair with given sum in BST
//not working

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

node* Insert(node *root,int value)
{
    if(root==NULL)
    {
        root=getnewnode(value);
    }
    if(root->data>value)
    {
        root->left=Insert(root->left,value);
    }
    if(root->data<value)
    {
        root->right=Insert(root->right,value);
    }
    return root;
}

vector<int> Inorder(node *root,vector<int> v)
{
    
    if(root==NULL)
        return v;
        
    Inorder(root->left,v);
    v.push_back(root->data);
    Inorder(root->right,v);
    
    return v;
}

int main()
{
    node *root=NULL;
    root=Insert(root,5);
    root=Insert(root,3);
    root=Insert(root,2);
    root=Insert(root,4);
    root=Insert(root,7);
    root=Insert(root,6);
    root=Insert(root,8);
    
    //find inorder and store it in vector;
    vector<int> v;
    v=Inorder(root,v);
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
}