#include<iostream>
#include<math.h>
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
int height(node* root)
{
   
    if(root==NULL)
    {
       return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
bool balanced_height_tree(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(balanced_height_tree(root->left)==false)
    {
        return false;
    }
    if(balanced_height_tree(root->right)==false)
    {
        return false;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1)
    {
        return true;
    }

}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    cout<<balanced_height_tree(root);
    return 0;
}
