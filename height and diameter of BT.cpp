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
int calc_height(node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int left_height=calc_height(root->left);
    int right_height=calc_height(root->right);
    return max(left_height,right_height) + 1;
}
int calc_diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_height=calc_height(root->left);
     int right_height=calc_height(root->right);
    int left_tree_diameter=calc_diameter(root->left);
    int right_tree_diameter=calc_diameter(root->right);
    int curr_diameter=left_height+right_height+1;

    return max(curr_diameter,max(left_tree_diameter,right_tree_diameter));
}
int diameter(node* root, int *height)
{
    if(root==NULL)
    {
       * height=0;
        return 0;
    }
    int lh=0; int rh=0;
    int left_diameter=diameter(root->left,&lh);
    int right_diameter=diameter(root->right,&rh);
    int curr=lh+rh+1;
    *height=max(lh,rh)+1;
 return max(curr,max(left_diameter,right_diameter));

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
   // cout<<calc_height(root);
   // cout<<calc_diameter(root);
   int height=0;
   cout<<diameter(root,&height);
    return 0;
}
