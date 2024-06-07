#include <bits/stdc++.h>
using namespace std;

struct Node{
     int val;
     Node* left,*right;
     Node(int x):val{x},left{nullptr},right{nullptr}{}
};
Node* inorderSuccessor(Node* root)
{
     while((root!=nullptr) && (root->left!=nullptr)) root=root->left;

     return root;
}
Node* Delete(Node* root,int x)
{
      if(root==nullptr) return nullptr;

      if(root->val==x)
      {
           if(root->left==nullptr) 
           {
                 Node* temp = root->right;
                 delete root;
                 return temp;
           }
           else if(root->right==nullptr){
                 Node* temp = root->left;
                 delete root;
                 return temp;
           }
           else
           {
            Node* res = inorderSuccessor(root->right);
            root->val=res->val;
            root->right = Delete(root->right,res->val);
           }
      }
      else if(root->val<x) root->right=Delete(root->right,x);
      else root->left = Delete(root->left,x);

      return root;
}
void inorder(Node* root)
{
     if(root==nullptr) return;

     inorder(root->left);
     cout<<root->val<<' ';
     inorder(root->right);
}
int main(){
     Node* root = new Node(50);
     root->left = new Node(30);
     root->left->left = new Node(20);
     root->left->right = new Node(40);
     root->right = new Node(70);
     root->right->left = new Node(60);
     root->right->right = new Node(80);


     root = Delete(root,50);
     inorder(root);
     cout<<'\n';
     return 0;
}