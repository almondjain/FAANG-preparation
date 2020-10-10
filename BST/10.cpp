#include<bits/stdc++.h>
using namespace std;

//check if two trees are identical or not
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

bool isequal(node *A, node *B)
{
    if(A==NULL && B==NULL)
        return true;
    if(A==NULL || B==NULL)
        return false;
        
    return(A->data==B->data && isequal(A->left,B->left) && isequal(A->right,B->right));
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
    rootB->left=getnewnode(2);
    rootB->right=getnewnode(3);
    rootB->right->left=getnewnode(4);
    rootB->right->right=getnewnode(5);

    /*
    rootA-
            1
        2       3
              4   5
    */
    
    if(isequal(rootA,rootB)==1)
        cout<<"Trees are identical"<<endl;
    else
        cout<<"Trees are not identical"<<endl;
}