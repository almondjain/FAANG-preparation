#include<bits/stdc++.h>
using namespace std;

//Implementation of BST
//2

struct node
{
    int data;
    struct node *left;
    struct node *right;
    
    // node(int data)
    // {
    //     this->data=data;
    //     left=NULL;
    //     right=NULL;
    // }
};

//generating a new node
node* getnewnode(int value)
{
    node* newnode = new node();
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

//Inserting an element
node* Insert(node* root, int target)
{
    if(root==NULL)//empty tree
    {
        root=getnewnode(target);
        return root;
    }
    else if(target <= root->data)
    {
        root->left = Insert(root->left,target);
    }
    else
    {
        root->right = Insert(root->right,target);
    }
    //this root will always be a main root, which is getting returned everytime, as their is recursive call
    return root;
}

//searching an element into BST
bool Search(node *root,int target)
{
    if(root==NULL)
        return false;
    else if(root->data==target)
        return true;
    else if(root->data>target)
        return Search(root->left,target);
    else
        return Search(root->right,target);
}

int main()
{
    node* root=NULL;
    //everytime returned root will be same
    root=Insert(root,1);
    root=Insert(root,2);
    root=Insert(root,3);
    root=Insert(root,4);
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,7);
    
    int num=9;
    if(Search(root,num)==true)
    {
        cout<<"Element found";
    }
    else
    {
        cout<<"Element not found";
    }
}