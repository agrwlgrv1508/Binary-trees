#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void rightview(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q1;
    q1.push(root);
    while(!q1.empty())
    {
       
        int n=q1.size();
       
       for(int i=0;i<n;i++)
       {
            node* curr=q1.front();
             q1.pop();
           if(i==n-1)
           {
               cout<<curr->data<<" ";
           }
           if(curr->left != NULL)
           {
               q1.push(curr->left);
           }
            if(curr->right != NULL)
           {
               q1.push(curr->right);
           }

       }
    }
   
}

void leftview(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q1;
    q1.push(root);
    
    while(!q1.empty())
    { 
        int n=q1.size();
        
        for(int i=0;i<n;i++)
    {
         node* curr=q1.front();
        q1.pop();
        if(i==n-1)
        {
            cout<<curr->data<<" ";
        }
        if(curr->right)
        {
            q1.push(curr->right);
        }
        if(curr->left != NULL)
        {
            q1.push(curr->left);
        }
        
    }
    }
   
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
   // rightview(root);
   leftview(root);
    return 0;
}