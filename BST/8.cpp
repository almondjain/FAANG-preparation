#include<bits/stdc++.h>
using namespace std;

//inverting a binary tree or mirror image of binary tree
//8

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

void Preorder(node *root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inverse(node *root)
{
    if(root==NULL)
        return;
        
        //we will traverse upto lastand get left and right node of respective root node
        //and thn just swap it
    Inverse(root->left);
    Inverse(root->right);
    
    node *temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}

int main()
{
    node *root = getnewnode(1);
    root->left=getnewnode(2);
    root->right=getnewnode(3);
    root->right->left=getnewnode(4);
    root->right->right=getnewnode(5);
    
    /*
    Tree:-
            1
        2       3
              4   5
              
preorder(root,left,right)--- 1,2,3,4,5

Inverting:-
            1
        3       2
      5   4   
      
preorder--- 1,3,5,4,2
    */
    
    cout<<"Preorder of tree before inverting it"<<endl;
    Preorder(root);
    
    Inverse(root);
    
    cout<<endl<<"Preorder of tree after inverting it"<<endl;
    Preorder(root);
}