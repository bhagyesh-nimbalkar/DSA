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
class Process{
    public:
      void Serialize(Node* root,vector<int>& arr)
      {
            if(root==nullptr) return;
            queue<Node*> q;
            q.push(root);
            arr.emplace_back(root->val);
          while(!q.empty())
          {
            if(q.front()->left==nullptr) arr.emplace_back(-1);
            else {
                arr.emplace_back(q.front()->left->val);
                q.push(q.front()->left);
            }
            if(q.front()->right==nullptr) arr.emplace_back(-1);
            else {
                arr.emplace_back(q.front()->right->val);
                q.push(q.front()->right);
            }
            q.pop();
          }
          for(int i=0;i<arr.size();i++) cout<<arr[i]<<' ';

          cout<<'\n';
      }
      Node* DeSerialize(vector<int> arr)
      {
           if(arr.size()==0) return nullptr;
           int k=1;
           Node* root = new Node(arr[0]);
           queue<Node*> q;
           q.push(root);
           for(int i=0;i<arr.size();i++)
           {
                 if(arr[i]==-1) continue;
                 Node* curr=q.front();
                 if(arr[k]==-1) curr->left=nullptr;
                 else{ 
                    curr->left = new Node(arr[k]);
                    q.push(q.front()->left);
                 }
                 if(arr[k+1]==-1) curr->right=nullptr;
                 else
                 { 
                    curr->right = new Node(arr[k+1]);
                    q.push(q.front()->right);
                 }
                 q.pop();
                 k+=2;
           }
           return root;
      }
      void inorder(Node* root)
      {
         if(root==nullptr) return;
         inorder(root->left);
         cout<<root->val<<" ";
         inorder(root->right);
      }
};
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->right = new Node(40);
    
    Process p;
    vector<int> res;
    p.Serialize(root,res);
    root = p.DeSerialize(res);
    p.inorder(root);
    cout<<'\n';
    return 0;
}