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

void printKNodes(Node* root,int k)
{
      if(root==nullptr) return;
      if(k==0) cout<<root->key<<" ";
      printKNodes(root->left,k-1);
      printKNodes(root->right,k-1);
}

int main()
{

    Node* root = new Node(10);
    root->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(12);
    root->left = new Node(6);
    root->right->right->left = new Node(11);
    printKNodes(root,3);
    cout<<'\n';
    return 0;
}