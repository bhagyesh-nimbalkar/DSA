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
bool ChK(Node* root,int x)
{
      if(root==nullptr) return true;
      bool res = ChK(root->left,x);
      if(res==false) return false;
      if(root->val<x) return false;
      else {
           x=root->val;
      }
      cout<<x<<'\n';
      res= ChK(root->right,x);
      if(res==false) return false;
      if(root->val<x) return false;
      else {
           x=root->val;
      }
      return true;
}
bool CheckBST(Node* root)
{
     return ChK(root,-1);
}
int main(){
    Node* root = new Node(80);
    root->left = new Node(70);
    root->left->left = new Node(60);
    root->left->right = new Node(75);
    root->right = new Node(90);
    root->right->left = new Node(85);
    root->right->right = new Node(100);
    cout<<boolalpha<<CheckBST(root)<<'\n';
    return 0;
}