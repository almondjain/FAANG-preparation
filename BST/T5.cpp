#include<bits/stdc++.h>
using namespace std;

//maximum sum path between any 2 leaves in a Binary Tree
//T5

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

int maxsumpathutil(node *root,int &res)
{
    if(root==NULL)
        return 0;
        
    //Leaf Node
    if(root->left==NULL && root->right==NULL)
        return root->data;
        
    int ls=maxsumpathutil(root->left,res);
    int rs=maxsumpathutil(root->right,res);
    
    if(root->left && root->right)
    {
        res=max(res,ls+rs+root->data);
        return max(ls,rs)+root->data;
    }
    
    return (!root->left)? rs+root->data: ls+root->data;
}

int maxsumpath(node *root)
{
    int res=INT_MIN;
    maxsumpathutil(root,res);
    
    return res;
}

int main()
{
    node *root=getnewnode(10);
    root->left=getnewnode(20);
    root->right=getnewnode(30);
    root->left->left=getnewnode(40);
    root->left->right=getnewnode(50);
    root->right->left=getnewnode(60);
    root->right->right=getnewnode(70);
    /*
            10
        20      30
    40  50    60  70
    */
    
    
    /*struct node *root = getnewnode(-15); 
    root->left = getnewnode(5); 
    root->right = getnewnode(6); 
    root->left->left = getnewnode(-8); 
    root->left->right = getnewnode(1); 
    root->left->left->left = getnewnode(2); 
    root->left->left->right = getnewnode(6); 
    root->right->left = getnewnode(3); 
    root->right->right = getnewnode(9); 
    root->right->right->right= getnewnode(0); 
    root->right->right->right->left= getnewnode(4); 
    root->right->right->right->right= getnewnode(-1); 
    root->right->right->right->right->left= getnewnode(10); 
    
    /*https://media.geeksforgeeks.org/wp-content/cdn-uploads/tree.png
    
    */
    
    cout<<maxsumpath(root);
    
}