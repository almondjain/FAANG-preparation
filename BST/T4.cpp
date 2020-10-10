#include<bits/stdc++.h>
using namespace std;

//find the max sum path from root to leaf node
//T4
//Binary Tree

struct node
{
    int data;
    node *left;
    node *right;
};

node* getnewnode(int value)
{
    node *root=new node();
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}

//get target leaf and max sum as a reference
void getTargetLeaf(node *root,int* max_sum_ref,int sum_here,node** target_leaf_ref)
{
    if(root==NULL)
        return;
        
    //update sum_here which will store current path node's sum which will be compared at last
    sum_here+=root->data;
    
    if(root->left==NULL && root->right==NULL)
    {
        if(sum_here>*max_sum_ref)
        {
            *max_sum_ref=sum_here;
            *target_leaf_ref=root;
        }
    }
    
    getTargetLeaf(root->left,max_sum_ref,sum_here,target_leaf_ref);
    getTargetLeaf(root->right,max_sum_ref,sum_here,target_leaf_ref);
}

//printing path for max sum
bool printPath(node *root,node *target_leaf)
{
    if(root==NULL)
        return false;
    
    if(root==target_leaf || printPath(root->left,target_leaf) || printPath(root->right,target_leaf))
    {
        cout<<root->data<<" ";
        return true;
    }
    
    return false;
}


//it is main fnx which will call two other fnx.
//one to find target leaf and max sum btw root and that target leaf
//and one to print the path from root to target leaf
int maxSumPath(node *root)
{
    if(root==NULL)
        return 0;
    
    node *target_leaf;
    int max_sum = INT_MIN;
    int sum=0;
    
    //find the target leaf and max sum
    //we will use call by reference so that value changed would be reflected in main one
    getTargetLeaf(root,&max_sum,sum,&target_leaf);
    
    //lets print path of max sum
    printPath(root,target_leaf);
    
    return max_sum;
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
        20       30
      40  50   60  70 
      
      max sum path-- 70+30+10=110
    */
    cout<<"Path for max sum path is "<<endl;
    //printpath() will do that inside maxsumpath() fnx.
    
    //it will return max sum
    int sum=maxSumPath(root);
    cout<<endl<<"Sum for max path is "<<sum<<endl;
    
    return 0;
}