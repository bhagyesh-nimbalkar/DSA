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
int isBalanced(Node* root)
{
    if(root==nullptr) return 0;
    int lh = isBalanced(root->left);
    if(lh==-1) return -1;
    int rh = isBalanced(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}
int main(){
    Node* root = new Node(18);
    root->left = new Node(4);
    root->right = new Node(20);
    root->right->left = new Node(13);
    root->right->right = new Node(70);
    root->right->right->right = new Node(90);
    cout<<boolalpha<<isBalanced(root)<<'\n';
    return 0;
}