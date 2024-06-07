#include <bits/stdc++.h>
using namespace std;

struct Node{
     int val;
     Node* left,*right;
     Node(int x)
     {
         val=x;
         left=right=nullptr;
     }
};
Node* first=nullptr,*second=nullptr;
void Swap(Node* root,int x,int y)
{
     if(root==nullptr ) return;

     if(root->val>x && root->val<y)
     {
          Swap(root->left,x,root->val);
          Swap(root->right,root->val,y);
     }
     else {
         if(first==nullptr) first=root;
         else second=root;
     }
     return;
}
Node* SwapNodes(Node* root)
{
      Swap(root,INT_MIN,INT_MAX);

      if(second==nullptr) second=root;
      int temp = first->val;
      first->val =second->val;
      second->val = temp;
      return root;
}
void inorder(Node* root)
{ 
     if(root==nullptr) return;
     inorder(root->left);
     cout<<root->val<<' ';
     inorder(root->right);
}
int main(){
    Node* root = new Node(60);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right = new Node(80);
    root->right->left = new Node(20);
    root->right->right = new Node(100);
    root = SwapNodes(root);
    inorder(root);
    cout<<'\n';
    return 0;
}