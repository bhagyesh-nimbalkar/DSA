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
void Itinorder(Node* root)
{
       if(root==nullptr) return;
       stack<Node*> st;
       st.push(root);
       while(!st.empty())
       {
           if(st.top()==nullptr){
            st.pop();
            continue;
           }
           if(st.top()->left==nullptr)
           {
               Node* curr = st.top();
               cout<<curr->val<<' ';
               st.pop();
               st.push(curr->right);
           }
           else{
               Node* curr=st.top()->left;
               st.top()->left=nullptr;
               st.push(curr);
           }
       }
       cout<<'\n';
}
int main()
{
    Node* root = new Node(10);
    /*root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(50);
    root->left->left->left->left = new Node(60);
    root->left->left->left->right = new Node(70);*/
    Itinorder(root);
    return 0;
}