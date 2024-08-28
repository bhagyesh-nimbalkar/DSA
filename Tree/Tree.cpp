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

void dfs(Node* root)
{
     if(root==nullptr) return;
     cout<<root->val<<'\n';
     dfs(root->left);
     dfs(root->right);
}
int main(){
    Node  *root = new Node(4);
    Node *child1 = new Node(3);
    Node *child2 = new Node(2);

    root->left=child1;
    root->right=child2;
    dfs(root);
   return 0;
}