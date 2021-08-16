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
// case1
void printSubtreenodes(node* root,int k)
{
    if(root==NULL || k<0)
    {
        return ;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
         return ;
    }
    printSubtreenodes(root->left,k-1);
    printSubtreenodes(root->right,k-1);
}
//case 2
int printNodes_at_k(node* root,node* target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        printSubtreenodes(root,k);
        return 0;
    }
    int dl=printNodes_at_k(root->left,target,k);
    if(dl != -1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
           
        }
        else{
              printSubtreenodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodes_at_k(root->right,target,k);
    if(dr != -1)
    {
        if(dr+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
              printSubtreenodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    cout<<printNodes_at_k(root,root->left,1);
    return 0;
}
