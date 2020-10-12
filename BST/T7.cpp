#include<bits/stdc++.h>
using namespace std;

//postorder traversal using single stack
//T7

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

void Postorder(node *root)
{
    stack<node*> s;
    while(true)
    {
        while(root!=NULL)
        {
            s.push(root);
            s.push(root);
            root=root->left;
        }
        
        if(s.empty())
            return;
            
        root=s.top();
        s.pop();
        
        if(!s.empty() && s.top()==root)
            root=root->right;
        else
        {
            cout<<root->data<<" ";
            root=NULL;
        }
    }
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
        20      30
     40   50   60  70
     
     p/o - 40,50,20,60,70,30,10
    */
    
    Postorder(root);
    
    return 0;
}