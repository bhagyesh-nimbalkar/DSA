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
int MaxWidth(Node* root)
{
      if(root==nullptr) return 0;
      queue<Node*> q;
      int Max=0;
      q.push(root);
      while(!q.empty())
      {
          int cnt=q.size();
          Max = max(cnt,Max);
          for(int i=0;i<cnt;i++)
          {
               if(q.front()->left!=nullptr) q.push(q.front()->left);
               if(q.front()->right!=nullptr) q.push(q.front()->right);
               q.pop();
          }
      }
      return Max;
}
int main(){
    Node* root = new Node(10);
   /* root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(80);
    root->right->left = new Node(50);
    root->right->right = new Node(60); */
    cout<<MaxWidth(root)<<'\n';
    return 0;
}