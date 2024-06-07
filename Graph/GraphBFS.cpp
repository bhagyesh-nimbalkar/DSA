#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<Node*> children;

    Node(int x)
    {
         val=x;
    }
    Node(int x,vector<Node*> v)
    {
         val=x;
         children=v;
    }
};
void Traverse(Node* root)
{
      if(root==nullptr) return;
      queue<Node*> q;
      q.push(root);
      unordered_set<int> st;
      while(!q.empty())
      {
        if(!st.count(q.front()->val)) 
        {
           cout<<q.front()->val<<' ';
           st.insert(q.front()->val);
        }
        for(auto x:q.front()->children)
        {
            q.push(x);
        }
        q.front()->children.clear();
        q.pop();
      }
      cout<<'\n';
      return;
}
int main()
{
     Node* root = new Node(0);
     Node* first = new Node(1);
     Node* second = new Node(2);
     Node* third = new Node(3);
     Node* four = new Node(4);
     Node* fifth  = new Node(5);
     root->children.push_back(first);
     root->children.push_back(second);
     root->children.push_back(fifth);
     first->children.push_back(third);
     first->children.push_back(root);
     second->children.push_back(root);
     second->children.push_back(four);
     third->children.push_back(first);
     third->children.push_back(fifth);
     four->children.push_back(second);
     four->children.push_back(fifth);
     fifth->children.push_back(third);
     fifth->children.push_back(four);
     Traverse(root);
     return 0;
}