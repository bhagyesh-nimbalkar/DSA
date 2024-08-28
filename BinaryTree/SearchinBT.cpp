#include <bits/stdc++.h>
using namespace std;

struct Node{
     int val;
     Node* left,*right;
     Node(int x):val{x},left{nullptr},right{nullptr}{}
};
bool isPresent(Node* root,int val)
{
      if(root==nullptr) return false;

      if(root->val==val) return true;
      else if(root->val<val) {
         return isPresent(root->right,val);
      }
      return isPresent(root->left,val);
}
int main(){
     Node* root = new Node(15);
     root->left = new Node(5);
     root->right = new Node(20);
     root->left->left = new Node(3);
     root->right->left = new Node(18);
     root->right->left->left = new Node(16);
     root->right->right  = new Node(80);
     cout<<boolalpha<<isPresent(root,15)<<'\n';
     return 0;
}