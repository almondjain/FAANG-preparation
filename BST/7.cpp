#include<bits/stdc++.h>
using namespace std;

//max depth or height of tree
//7

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

int height(node *root)
{
    if(root==NULL)
        return 0;
        
    int lh=height(root->left);
    int rh=height(root->right);
    
    return(1+max(lh,rh));
}
int main()
{
    node *root=getnewnode(1);
    root->left=getnewnode(2);
    root->right=getnewnode(3);
    root->left->left=getnewnode(5);
    root->left->left->right=getnewnode(6);
    
    cout<<height(root);
}