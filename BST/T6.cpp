#include<bits/stdc++.h>
using namespace std;

//closest element in binary search tree based on min absolute difference
//T6

//here we need to return node from bst, having min diff with given key value

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

node* Insert(node *root, int value)
{
    if(root==NULL)
        root=getnewnode(value);
    
    if(value<root->data)
        root->left=Insert(root->left,value);
    if(value>root->data)
        root->right=Insert(root->right,value);
        
    return root;
}

void minDistanceUtil(node *root,int key,int &min_dist,int &min_dist_value)
{
    if(root==NULL)
        return;
    
    //return same, if node is key as diff would be 0 among them
    if(root->data==key)
    {
        min_dist_value=root->data;
        return;
    }
    
    //updating min_dist and min_dist_value
    if(min_dist > (abs(root->data - key)) )
    {
        min_dist=abs(root->data - key);
        min_dist_value=root->data;
    }
    
    if(key<root->data)
        minDistanceUtil(root->left, key, min_dist, min_dist_value);
    else
        minDistanceUtil(root->right, key, min_dist, min_dist_value);
    
}

int minDistance(node *root,int key)
{
    //min_dist = to store min diff between given key and traversed nodes,we will keep updating ds by comparing it with each node
    //min_dist_value = it will keep value of node that is having min distance with key value
    int min_dist=INT_MAX;
    int min_dist_value;
    
    minDistanceUtil(root,key,min_dist,min_dist_value);
    
    return min_dist_value;
}

int main()
{
    node *root=NULL;
    root=Insert(root,9);
    root=Insert(root,4);
    root=Insert(root,3);
    root=Insert(root,6);
    root=Insert(root,5);
    root=Insert(root,7);
    root=Insert(root,17);
    root=Insert(root,22);
    root=Insert(root,20);
    
    //we are given with bst and key value, i.e required node (find node closest to this value)
    int key=12;
    cout<<minDistance(root,key);
    
    return 0;
}