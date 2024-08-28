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
int SizeofTree(Node* root)
{
     if(root==nullptr) return 0;
     return SizeofTree(root->left)+SizeofTree(root->right)+1;
}
int main(){
    Node* root = new Node(80);
    root->left = new Node(30);
    root->right = new Node(40);
    /*root->left->left = new Node(90);
    root->right->right = new Node(100);
    root->right->right->left = new Node(60);*/

    cout<<SizeofTree(root)<<'\n';
    return 0;
}