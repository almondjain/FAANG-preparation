#include<bits/stdc++.h>
using namespace std;

//Traversing of Binary Tree using DFS approach
//3

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

//will use recursion for all 3 methods

void preorder(struct node *root)
{
    //root,left,right
    if(root==NULL)
        return;
    
    cout<<root->data<<" "; //root
    preorder(root->left); //left
    preorder(root->right); //right
}

void InOrder(struct node *root)
{
    //left,root,right
    if(root==NULL)
        return;
    
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(struct node *root)
{
    //left,right,root
    if(root==NULL)
        return;
        
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    /*
           1
       2       3
    4    5   6    7
    */
    
    cout<<endl<<"Preorder traversal is"<<endl;
    preorder(root);
    
    cout<<endl<<"Inorder traversal is"<<endl;
    InOrder(root);
    
    cout<<endl<<"PostOrder traversal is"<<endl;
    PostOrder(root);
    
    return 0;
}