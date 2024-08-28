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
void Itpreorder(Node* root)
{
      if(root==nullptr) return;
      stack<Node*> st;
      st.push(root);
      while(!st.empty())
      {
           cout<<st.top()->val<<' ';
           Node* curr = st.top();
           st.pop();
           if(curr->right!=nullptr) st.push(curr->right);
           if(curr->left!=nullptr) st.push(curr->left);
      }
      cout<<'\n';
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right= new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(60);
    root->right->right->right = new Node(70);
    Itpreorder(root);
    return 0;
}