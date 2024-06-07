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
void TraverseInSpiral(Node* root)
{
      if(root==nullptr) return;
      queue<Node*> q;
      q.push(root);
      bool flag=true;
      while(!q.empty())
      {
        int cnt = q.size();
        if(flag)
        {
          for(int i=0;i<cnt;i++)
          {
               cout<<q.front()->data<<' ';
               if(q.front()->left!=nullptr) q.push(q.front()->left);
               if(q.front()->right!=nullptr) q.push(q.front()->right);

               q.pop();
          }
        }
        else {
              vector<int> v;
              for(int i=0;i<cnt;i++)
              {
               v.emplace_back(q.front()->data);
               if(q.front()->left!=nullptr) q.push(q.front()->left);
               if(q.front()->right!=nullptr) q.push(q.front()->right);

               q.pop();
              }
              for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
        }
        flag=!flag;
      }
      cout<<'\n';
}
int main(){
     Node* root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     root->right->left = new Node(6);
     root->right->right = new Node(7);
     root->left->left->left = new Node(8);
     root->left->left->right = new Node(9);
     root->right->left->left = new Node(10);
     TraverseInSpiral(root);
     return 0;
}