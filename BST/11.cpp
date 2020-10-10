#include<bits/stdc++.h>
using namespace std;

//find nth node of inorder traversal
//11

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

void nthNode(node *root,int n)
{
    static int count=0;
    
    if(root==NULL)
        return;
    
    if(count<=n)
    {
        nthNode(root->left,n);
    
        count++;
        if(count==n)
        {
            int temp=root->data;
            cout<<n<<" node for inorder traversal is "<<temp;
        }
    
        nthNode(root->right,n);
        
    }
}

int main()
{
    node *root= getnewnode(10);
    root->left=getnewnode(20);
    root->left->left=getnewnode(30);
    root->left->right=getnewnode(40);
    root->right=getnewnode(50);
    root->right->left=getnewnode(60);
    root->right->right=getnewnode(70);
    
    /*
    tree-
             10
        20         50
    30     40   60     70
    
    inorder traversal- left,root,right
    30,20,40,10,60,50,70
    
    n=4
    0/p - 10
    */
    int n;
    cout<<"Enter node for inorder traversal"<<endl;
    cin>>n;
    
    nthNode(root,n);

    return 0;
}