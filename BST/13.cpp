#include<bits/stdc++.h>
using namespace std;

//sum of all nodes in a binary tree
//13
//approach 2- recursive method

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

int sumNode(node *root)
{
    if(root==NULL)
        return 0;
        
    return(root->data+sumNode(root->left)+sumNode(root->right));
        
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
    
    sum = 280
    */
    
    cout<<sumNode(root);

    return 0;
}