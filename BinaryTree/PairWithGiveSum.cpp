#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int val;
     Node* left,*right;
     Node(int x)
     {
         val=x;
         left=right=nullptr;
     }
};
bool isPair(Node* root,int sum,unordered_set<int>& mp)
{
     if(root==nullptr) return false;

     bool res1 = isPair(root->left,sum,mp);
     if(res1) return true;
     if(mp.count(sum-root->val)) return true;
     mp.insert(root->val);
     return isPair(root->right,sum,mp);
}
bool FindPair(Node* root,int sum)
{
     unordered_set<int> mp;
     return isPair(root,sum,mp);
}
int main(){
     Node* root = new Node(10);
     root->left = new Node(5);
     root->right = new Node(20);
     root->right->left = new Node(16);
     root->right->right = new Node(40);

     cout<<boolalpha<<FindPair(root,21)<<'\n';
     return 0;
}