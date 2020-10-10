#include<bits/stdc++.h>
using namespace std;

//cousins of given node
//16

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

int getlevel(node *root,node *temp,int level)
{
    if(root==NULL)
        return 0;
    if(root==temp)
        return level;
    int downlevel=getlevel(root->left,temp,level+1);
    int highlevel=getlevel(root->right,temp,level+1);
    if(downlevel!=0)
        return downlevel;
     if(highlevel!=0)
         return highlevel;
    
    //return(getlevel(root->right,temp,level+1));
}

void printGivenLevel(node* root, node *temp, int level) 
{ 
    // Base cases 
    if (root == NULL || level < 2) 
        return; 
  
    // If current node is parent of a node  
    // with given level 
    if (level == 2) 
    { 
        if (root->left == temp || root->right == temp) 
            return; 
        if (root->left) 
            cout << root->left->data << " "; 
        if (root->right) 
            cout << root->right->data; 
    } 
  
    // Recur for left and right subtrees 
    else if (level > 2) 
    { 
        printGivenLevel(root->left, temp, level - 1); 
        printGivenLevel(root->right, temp, level - 1); 
    } 
} 
  
void printCousins(node *root, node *temp) 
{ 
    // Get level of given node 
    int level = getlevel(root, temp, 1); 
  
    // Print nodes of given level. 
    printGivenLevel(root, temp, level); 
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
    
        */
    
    node *temp=root->right->right;
    printCousins(root,temp);

    return 0;
}