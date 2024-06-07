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
int Height(Node* root)
{
     if(root==nullptr) return 0;

     int left = Height(root->left)+1;
     int right = Height(root->right)+1;

     return max(left,right);
}
int main()
{
    Node* root = new Node(30);
    root->left = new Node(40);
    root->right = new Node(60);
    root->left->left = new Node(70);
    //root->left->left->left= new Node(80);

    cout<<Height(root)<<'\n';
    return 0;
}