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
class Solution{
private:
  unordered_map<Node*,pair<int,int>> mp;
  int Max=0;
public:
  int store(Node* root)
  {
      if(root==nullptr) return 0;

      int left = store(root->left);
      int right = store(root->right);

      mp[root].first=left;
      mp[root].second=right;

      return max(left,right)+1;
  }
  pair<bool,int> LCA(Node* root,Node* leaf)
  {
      if(root==nullptr) return {false,0};

      if(root->val==leaf->val) return {true,1};

      pair<bool,int> left = LCA(root->left,leaf);
      pair<bool,int> right = LCA(root->right,leaf);

      if(left.first){
            Max=max(Max,left.second+1+mp[root].second);
            cout<<root->val<<'\n';
            return {left.first,left.second+1};
      }
      else if(right.first){
             Max=max(Max,right.second+1+mp[root].first);
             cout<<root->val<<'\n';
            return {right.first,right.second+1};
      }
      return {false,0};
  }
  int BurnTree(Node* root,Node* leaf)
  {
       store(root);
       LCA(root,leaf);
       return Max;
  }
};
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    //root->left->left->left->left = new Node(60);
    //root->left->left->left->left->left = new Node(70);
    root->left->left->right = new Node(50);
    Solution s;
    cout<<s.BurnTree(root,root->left->left->right)<<'\n';
    return 0;
}