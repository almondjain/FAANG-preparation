#include<bits/stdc++.h>
using namespace std;

//sum of all nodes in a binary tree
//12
//approach 1- traverse a tree using inorder approach and keep adding value

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
    static int sum=0;
    
    if(root==NULL)
        return 0;
    

    sumNode(root->left);

    sum+=root->data;
    
    sumNode(root->right);
    
    return sum;
    
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
    
    inorder traversal- left,root,right
    30,20,40,10,60,50,70
    sum = 280
    */
    
    cout<<sumNode(root);

    return 0;
}