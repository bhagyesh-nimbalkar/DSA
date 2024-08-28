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

void postorder(Node* root)
{
     if(root==nullptr) return;
     postorder(root->left);
     postorder(root->right);
     cout<<root->key<<' ';
}
void preorder(Node* root)
{
     if(root==nullptr) return;
     cout<<root->key<<" ";
     preorder(root->left);
     preorder(root->right);
}
void inorder(Node* root)
{
      if(root==nullptr) return;
      inorder(root->left);
      cout<<root->key<<' ';
      inorder(root->right);
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left= new Node(40);
    root->left->right=new Node(50);
    root->left->right->left=new Node(70);
    root->left->right->right=new Node(80);
    root->right=new Node(30);
    root->right->right = new Node(60);

    cout<<"Inorder:";
    inorder(root);
    cout<<'\n';
    cout<<"Preorder:";
    preorder(root);
    cout<<'\n';
    cout<<"Postorder:";
    postorder(root);
    cout<<'\n';
    return 0;
}