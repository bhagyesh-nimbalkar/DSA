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
int MaxinTree(Node* root)
{
     if(root==nullptr) return 0;

     return max(root->data,max(MaxinTree(root->left),MaxinTree(root->right)));
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(80);
    root->right->right = new Node(20);
    root->right->left = new Node(60);
    cout<<MaxinTree(root)<<'\n';
    return 0;
}