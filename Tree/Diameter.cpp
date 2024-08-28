#include <bits/stdc++.h>
using namespace std;

struct Node{
     int data;
     Node* left,*right;
     Node(int x)
     {
         data =x;
         left=right=nullptr;
     }
};

int Height(Node* root,unordered_map<Node*,int>& mp)
{
       if(root==nullptr) return 0;

       int left = Height(root->left,mp);
       int right = Height(root->right,mp);

       mp[root]=max(left,right)+1;
       return max(left,right)+1;
}
int Diameter(Node*root,unordered_map<Node*,int>& mp)
{
      if(root==nullptr) return 0;
      int left=0,right=0;
      if(root->left!=nullptr) left= mp[root->left];
      if(root->right!=nullptr) right=mp[root->right];

      return max(left+right+1,Diameter(root->left,mp)+Diameter(root->right,mp));
}
int TreeDiameter(Node* root)
{
     unordered_map<Node*,int> mp;
     Height(root,mp);
     return Diameter(root,mp);
}
int main(){
     Node* root = new Node(10);
     root->left=new Node(20);
     root->right = new Node(30);
     root->right->left=new Node(40);
     root->right->left->left = new Node(60);
     root->right->right=new Node(50);
     cout<<TreeDiameter(root)<<'\n';
     return 0;
}