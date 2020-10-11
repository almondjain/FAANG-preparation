#include<bits/stdc++.h>
using namespace std;

//find a pair with given sum in BST
//19

struct node
{
    int data;
    node *left, *right;
};

node* getnewnode(int value)
{
    node *root=new node();
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}

node* Insert(node *root,int value)
{
    if(root==NULL)
        root=getnewnode(value);
    
    if(value<root->data)
        root->left=getnewnode(value);
    else
        root->right=getnewnode(value);
        
    return root;
}

bool pairSumutil(node *root,int sum,set<int> &s)
{
    if(root==NULL)
        return false;
    
    if(pairSumutil(root->left,sum,s))
        return true;
    
    if(s.find(sum-root->data)!=s.end())
    {
        //pair found
        cout<<"Pair with given sum "<<sum<<" is "<<sum-root->data<<" & "<<root->data<<endl;
        return true;
    }
    else
    {
        s.insert(root->data);
    }
    
    return(pairSumutil(root->right,sum,s));
}

void pairSum(node *root,int sum)
{
    set<int> s;
    if(!pairSumutil(root,sum,s))
        cout<<"Pairs donot exist"<<endl;
}

int main()
{
    node *root=NULL;
    root = Insert(root, 15); 
    root = Insert(root, 10); 
    root = Insert(root, 20); 
    root = Insert(root, 8); 
    root = Insert(root, 12); 
    root = Insert(root, 16); 
    root = Insert(root, 25); 
    
    int sum=18;
    pairSum(root,sum);
  
}