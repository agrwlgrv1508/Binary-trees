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
void level_order_traversal(node* root)
{
    queue<node*> q1;
    if(root==NULL)
    {
        return;
    }
    q1.push(root);
    q1.push(NULL);
    
    while(!q1.empty())
    {
        
        node* temp=q1.front();
        q1.pop();
        if(temp != NULL)
        {
            cout<<temp->data<<" ";
            
            if(temp->left)
            {
               q1.push(temp->left);
            }
            if(temp->right)
            {
                q1.push(temp->right);
            }
            
        }
        else{
            if(!q1.empty())
            {
                q1.push(NULL);
            }
            
        }
    }
}
int sum(node* root,int k)
{
    int counter=0;
    int sum=0;
    if(root==NULL)
    {
        return 0;
    }
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(counter !=k)
    {
       node* temp=q1.front();
       q1.pop();
       
       if(temp != NULL)
       {
      /* 	if(counter==k)
       {
       	sum+=temp->data;
	   }*/
           if(temp->left)
           {
               q1.push(temp->left);
           }
           if(temp->right)
           {
               q1.push(temp->right); 
           }
       }
       else
       {
           if(!q1.empty())
           {
               q1.push(NULL);
               counter++;
           }
       }

    }
    
    while(q1.front()!= NULL)
    {
        node* temp2=q1.front();
        q1.pop();
        sum=sum+temp2->data;
    }

  return sum;
}
int main()
{
    node* root=new node(5);
    root->left=new node(6);
    root->right=new node(3);
    root->left->left=new node(9);
    root->left->right=new node(1);
    root->right->left=new node(2);
    root->right->right=new node(1);
    root->left->right->left=new node(2);
    root->left->right->left->left=new node(3);
    root->left->right->left->right=new node(5);
   root->right->left->right=new node(6);
   root->right->left->right->right=new node(7);
    //level_order_traversal(root);
    int k=3;
    cout<<sum(root,k);
    return 0;
}
