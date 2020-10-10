#include<bits/stdc++.h>
using namespace std;

//Implementation of Binary search tree
//1

struct node 
{
    int data;
    struct node *left=NULL;
    struct node *right=NULL;
    node(int val)
    {
        data = val;
    }
};

//here we are just initialising nodes and giving respective value to them

int main()
{
    struct node *root=new node(1);
    root->left= new node(2);
    root->right=new node(3);
    return 0;
}