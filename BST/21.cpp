#include<bits/stdc++.h>
using namespace std;

//Print all k sum paths in a binary tree
//21

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

void printPath(vector<int> &v,int j)
{
    for(int i=j; i<v.size() ;i++)
        cout<<v[i]<<" ";
    
    cout<<endl;
}

void KsumpathUtil(node *root,int sum,vector<int> &v)
{
    if(root==NULL)
        return;
    
    v.push_back(root->data);
    
    KsumpathUtil(root->left,sum,v);
    KsumpathUtil(root->right,sum,v);
    
    int f=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        f+=v[i];
        if(f==sum)
            printPath(v,i);
    }
    v.pop_back();
}

void Ksumpath(node *root,int sum)
{
    //take vector to store path in every iteration
    vector<int> v;
    KsumpathUtil(root,sum,v);
}

int main()
{
    node *root=getnewnode(1);
    root->left=getnewnode(7);
    root->right=getnewnode(3);
    root->right->left=getnewnode(5);
    root->right->right=getnewnode(4);
    
    /*
            1
        7       3
              5   4
    */
    
    int sum=8;
    Ksumpath(root,sum);
    
    return 0;

}