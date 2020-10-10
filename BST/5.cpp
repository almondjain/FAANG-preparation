#include<bits/stdc++.h>
using namespace std;

//Implementation of BST
//2
//create BST and search nodes in it

//not working

struct node
{
    int data;
    node *left=NULL;
    node *right=NULL;
};

//fnx to create new node
node* getnewnode(int value)
{
    node *newnode = new node();
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

//inserting data in BST
//we return the node as rootnode while inserting
node* Insert(node* root, int value)
{
    if(root==NULL)
    {
        //empty tree
        root = getnewnode(value);
    }
    if(value<=root->data)
    {
        root->left = Insert(root->left,value);
    }
    else
    {
        root->right = Insert(root->right,value);
    }
    return root;
}

//Searching an element in BST
//using recursion here
bool Search(node* root,int value)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==value)
    {
        return true;
    }
    else if(value <= root->data)
    {
       return Search(root->left,value);
    }
    else
    {
        return Search(root->right,value);
    }
}

int main()
{
    node *root=NULL;
    //inserting
    root = Insert(root,1);
    node *start = root;
    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,4);
    root = Insert(root,5);
    root = Insert(root,6);
    
    int num=1;
    if(Search(start,num)==true)
    {
        cout<<"Element found";
    }
    else
    {
        cout<<"Element not found";
    }
}