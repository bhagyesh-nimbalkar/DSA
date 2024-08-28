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
void PreCompute(Node* root,map<int,vector<int>>& mp,int hd)
{
     if(root==nullptr) return;
     mp[hd].emplace_back(root->val);
     PreCompute(root->left,mp,hd-1);
     PreCompute(root->right,mp,hd+1);
}
vector<vector<int>> VerticalTraversal(Node* root)
{
     map<int,vector<int>> mp;
     PreCompute(root,mp,0);
     vector<vector<int>> ans;
     for(auto& d:mp)
     {
         ans.emplace_back(d.second);
     }
     return ans;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left= new Node(40);
    root->left->right = new Node(50);
    
    vector<vector<int>> res = VerticalTraversal(root);
    for(int i=0;i<res.size();i++)
    {
         for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<' ';
         cout<<'\n';
    }
    return 0;
}