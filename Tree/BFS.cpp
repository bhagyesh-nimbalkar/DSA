#include <bits/stdc++.h>
using namespace std;

struct Node{
     int key;
     Node* left,*right;
     Node(int x)
     {
         key=x;
         left=right=nullptr;
     }
};
void LevelOrder(Node* root)
{ 
     queue<Node*> q;
     if(root==nullptr) return;
     q.push(root);
     while(!q.empty())
     {
          int count = q.size();
          for(int i=0;i<count;i++)
          {
               cout<<q.front()->key<<" ";
               if(q.front()->left!=nullptr) q.push(q.front()->left);
               if(q.front()->right!=nullptr) q.push(q.front()->right);
               q.pop();
          }
          cout<<'\n';
     }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);

    LevelOrder(root);
    return 0;
}