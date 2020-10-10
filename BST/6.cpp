#include<bits/stdc++.h>
using namespace std;

//diameter of binary tree
//6

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

int height(node *root)
{
    if(root==NULL)
        return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    return(1+max(lh,rh));
}

int diameter(node* root)
{
    if(root==NULL)
        return 0;
    
    int lh=height(root->left);
    int rh = height(root->right);
    /*
    int ld= diameter(root->left);
    int rd= diameter(root->right);
    
    return max(max(ld,rd),(lh+rh+1));
*/
    return(lh+rh+1);
}

int main()
{
    node *root=getnewnode(1);
    root->left=getnewnode(2);
    root->left->left=getnewnode(3);
    root->left->right=getnewnode(4);
    root->right=getnewnode(5);
    root->right->left=getnewnode(6);
    root->right->right=getnewnode(7);
    
    /*
             1
        2         5
    3      4    6     7
    */
    
    cout<<diameter(root);
    
}