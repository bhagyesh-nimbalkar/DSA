#include <bits/stdc++.h>
using namespace std;

struct Node{
     int val;
     Node* left,*right;
     Node(int x){
        val=x;
        left=right=nullptr;
     }
};
class Solution{
private:
Node* prev=nullptr;
public:
Node* ConvertDLL(Node* root)
{
     if(root==nullptr) return nullptr;
     Node* head = ConvertDLL(root->left);

     if(prev==nullptr){head=root;}
     else {
          root->left=prev;
          prev->right=root;
     }
     prev=root;
     ConvertDLL(root->right);
     return head;
}
void Traverse(Node* root)
{
      while(root!=nullptr){
         cout<<root->val<<' ';
         root=root->right;
      }
      cout<<'\n';
}
};
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right= new Node(20);
    root->right->left= new Node(30);
    root->right->right = new Node(35);
    Solution s;
    Node* head = s.ConvertDLL(root);
    s.Traverse(head);
    return 0;
}
