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
void inorder(Node* root,map<int,int>& mp,int cnt)
{
     if(root==nullptr) return;

     inorder(root->left,mp,cnt-1);
     mp[cnt]+=root->val;
     inorder(root->right,mp,cnt+1);
}
vector<int> VerticalSum(Node* root)
{
     map<int,int> mp;
     vector<int> v;
     inorder(root,mp,0);
     for(auto& d:mp)
     {
         v.emplace_back(d.second);
     }
     return v;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(25);
    root->left->left= new Node(35);
    root->left->right = new Node(20);
    root->left->right->right = new Node(75);
    root->left->right->right->right = new Node(80);
    root->left->left->left = new Node(40);

    vector<int> res = VerticalSum(root);
    for(int i=0;i<res.size();i++) cout<<res[i]<<' ';
    cout<<'\n';
    return 0;
}