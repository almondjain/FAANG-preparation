#include<bits/stdc++.h>
using namespace std;

//check if two trees are mirror of each other
//9

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

bool aremirror(node *A, node *B)
{
    if(A==NULL && B==NULL)
        return true;
    if(A==NULL || B==NULL)
        return false;
        
    return(A->data==B->data && aremirror(A->left,B->right) && aremirror(A->right,B->left));
}

int main()
{
    node *rootA=getnewnode(1);
    rootA->left=getnewnode(2);
    rootA->right=getnewnode(3);
    rootA->right->left=getnewnode(4);
    rootA->right->right=getnewnode(5);
    
    /*
    rootA-
            1
        2       3
              4   5
    */
    
    node *rootB=getnewnode(1);
    rootB->left=getnewnode(3);
    rootB->left->left=getnewnode(5);
    rootB->left->right=getnewnode(4);
    rootB->right=getnewnode(2);
    
    /*
    rootB-
            1
        3       2
      5   4          
    */
    
    if(aremirror(rootA,rootB)==1)
        cout<<"Both Trees are mirror image of each other"<<endl;
    else
        cout<<"Both Trees are not mirror image of each other"<<endl;
}