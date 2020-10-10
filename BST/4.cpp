#include<bits/stdc++.h>
using namespace std;

//Traversing of Binary Tree using BFS approach
//4
//Queue approach

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

void LevelOrder(node *root)
{
    if(root==NULL)
        return;
    queue<node *> q;
    q.push(root);
    
    while(!q.empty())
    {
        node *curr = q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    /*
           1
       2       3
    4    5   6    7
    */
    
    LevelOrder(root);
    return 0;
}