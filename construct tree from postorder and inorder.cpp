#include<iostream>
using namespace std;

class node{
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
node* binary_tree(int postorder[],int inorder[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    static int idx=end;
    int curr=postorder[idx];
    node* root=new node(curr);
    idx--;
   
    if(start==end)
    {
     return root;
    }
    int pos=search(inorder,start,end,curr);
    root->right=binary_tree(postorder,inorder,pos+1,end);
    root->left=binary_tree(postorder,inorder,start,pos-1);
    return root;
}
void inorder_sequence(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_sequence(root->left);
    cout<<root->data<<" ";
    inorder_sequence(root->right);
}
int main()
{
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    node* res=binary_tree(postorder,inorder,0,4);
    inorder_sequence(res);
    return 0;
}
