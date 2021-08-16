#include<iostream>
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

node* LCA(node* root,int n1, int n2)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    node* left_LCA=LCA(root->left,n1,n2);
    node* right_LCA=LCA(root->right,n1,n2);

    if(left_LCA && right_LCA)
    {
        return root;
    }
    if(left_LCA != NULL)
    {
        return left_LCA;
    }
    return right_LCA;
}
int distance(node* root,int n,int d)
{
   if(root==NULL)
   {
       return 0;
   }
   if(root->data==n)
   {
       return d;
   }
   int left=distance(root->left,n,d+1);
   if(left != 0)
   {
   	  return left;
   }
   return distance(root->right,n,d+1);
}
int main()
{
      node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    
    root->right->right=new node(5);
    
    node* lca=LCA(root,4,5);
    int d1=distance(lca,4,0);
    int d2=distance(lca,5,0);
    cout<<d1+d2;
   // cout<<"LCA: "<<lca->data;
    return 0;
}
