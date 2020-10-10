#include<bits/stdc++.h>
using namespace std;

//level of a node in a tree
//15

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

int getlevel(node *root,node *temp,int level)
{
    if(root==NULL)
        return 0;
    if(root==temp)
        return level;
    int downlevel=getlevel(root->left,temp,level+1);
    int highlevel=getlevel(root->right,temp,level+1);
    if(downlevel!=0)
        return downlevel;
     if(highlevel!=0)
         return highlevel;
    
    //return(getlevel(root->right,temp,level+1));
}


int main()
{
    node *root= getnewnode(10);
    root->left=getnewnode(20);
    root->left->left=getnewnode(30);
    root->left->right=getnewnode(40);
    root->right=getnewnode(50);
    root->right->left=getnewnode(60);
    root->right->right=getnewnode(70);
    
    /*
    tree-
             10
        20         50
    30     40   60     70
    
        */
    
    node *temp=root->right->right;
    cout<<getlevel(root,temp,1);

    return 0;
}