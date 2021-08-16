#include<iostream>
#include<vector>
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
bool get_path(node* root,int key,vector<int> &path)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data == key)
    {
        return true;
    }
    if(get_path(root->left,key,path) || get_path(root->right,key,path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int lowest_common_ancestor(node* root,int n1,int n2)
{
    vector<int> path1,path2;

    if(!get_path(root,n1,path1) || !get_path(root,n2,path2))
    {
        return -1;
    }
    int pc=0;
    while(pc<path1.size() && pc<path2.size())
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
        pc++;
    }
    return path1[pc-1];
}
node* LCA2(node* root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    node* left_LCA=LCA2(root->left,n1,n2);
    node* right_LCA=LCA2(root->right,n1,n2);

    if( left_LCA && right_LCA)
    {
        return root;
    }
    if(left_LCA != NULL)
    {
        return left_LCA;
    }
    return right_LCA;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);
    root->right->left->left=new node(7);
 //  int lca= lowest_common_ancestor(root,7,6);
 node* lca= LCA2(root,7,6);
   if(lca->data ==-1)
   {
       cout<<"LCA is missing";
   }
   else{
       cout<<"LCA: "<<lca->data;
   }
    return 0;
}
