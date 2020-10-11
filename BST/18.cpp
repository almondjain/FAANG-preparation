#include<bits/stdc++.h>
using namespace std;

//closest leaf to a given node in a binary tree
//18

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

void findleafnode(node *root,int lev,int *minDist)
{
    if(root==NULL)
        return;
        
    //Leaf node
    if(root->left==NULL && root->right==NULL)
    {
        if(lev<*minDist)
            *minDist=lev;
        return;
    }
    
    //recur for left and right subtrees
    findleafnode(root->left,lev+1,minDist);
    findleafnode(root->right,lev+1,minDist);
}

int findthroughParent(node *root, node *x,int *minDist)
{
    if(root==NULL)
        return -1;
        
    if(root==x)
        return 0;
        
    //search x in left subtree of root
    int l=findthroughParent(root->left,x,minDist);
    //if found in left
    if(l!=-1)
    {
        //traverse in right
        findleafnode(root->right,l+2,minDist);
        return l+1;
    }
    
    //search x in right subtree of root
    int r=findthroughParent(root->right,x,minDist);
    //if found in right
    if(r!=-1)
    {
        //traverse in left
        findleafnode(root->left,l+2,minDist);
        return l+1;
    }
    
    return -1;
}

int minimumdistance(node *root,node *x)
{
    int minDist=INT_MAX;
    
    findleafnode(x,0,&minDist);
    
    findthroughParent(root,x,&minDist);
    
    return minDist;
}

int main()
{
    node *root=getnewnode(10);
    root->left=getnewnode(12);
    root->right=getnewnode(13);
    root->right->left=getnewnode(14);
    /*
            10
        12      13
              14
    */
    
    cout<<minimumdistance;
}