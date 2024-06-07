#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val=-1;
    Node* left,*right;
    Node(int x){
        val=x;
        left=right=nullptr;
    }
};
class Solution{
public:
Node* FloorinBST(Node* root,int k)
{
     Node* res=nullptr;
     Node* curr = root;
     while(curr!=nullptr)
     {
           if(curr->val==k){
             res=curr;
             break;
           }
          if(curr->val<=k){
              if(res==nullptr) res=curr;
              else {
                if(res->val<curr->val){
                    res=curr;
                }
              }
              curr=curr->right;
          }
          else {
            curr=curr->left;
          }
     }
     return res;
}
};
int main()
{
     Node* root = new Node(10);
     root->left = new Node(5);
     root->right = new Node(15);
     root->right->left = new Node(12);
     root->right->right = new Node(30);

     Solution s;
     Node* res = s.FloorinBST(root,7);
     if(res==nullptr) cout<<"Null\n";
     else cout<<res->val<<'\n';
     return 0;
}