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
int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
node* binary_tree(int preorder[],int inorder[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    static int idx=0;
    int curr=preorder[idx];
    idx++;
    node* root=new node(curr);
    if(start==end)
{
    return root;
}
int pos=search(inorder,start,end,curr);

    root->left=binary_tree(preorder,inorder,start,pos-1);
    root->right=binary_tree(preorder,inorder,pos+1,end);
    return root;
}  
void inorder_sequence(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder_sequence(root->left);
    cout<<root->data<<" ";
    inorder_sequence(root->right);
}
int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    
    node* Node=binary_tree(preorder,inorder,0,4);
    inorder_sequence(Node);
    return 0;
}