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

void LeftView(Node* root)
{
     if(root==nullptr) return;
     queue<Node*> q;
     cout<<root->data<<" ";
     q.push(root->left);
     q.push(root->right);
     while(!q.empty())
     {
         if(q.front()==nullptr) {
            q.pop();
            continue;
         }
         int cnt = q.size();
         for(int i=0;i<cnt;i++)
         {
            if(i==0)
            {
                cout<<q.front()->data<<" ";
            }
         if(q.front()->left!=nullptr) q.push(q.front()->left);
         if(q.front()->right!=nullptr) q.push(q.front()->right);
         q.pop();
         }
     }
     cout<<'\n';
     return;
}
int main(){
    Node* root = new Node(30);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->left->right= new Node(10);
    
    LeftView(root);
    return 0;
}