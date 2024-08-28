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

pair<bool,int> ChildrenSumProp(Node* root)
{
     if(root==nullptr) return {true,-1};
     
     pair<bool,int> left = ChildrenSumProp(root->left);
     pair<bool,int> right = ChildrenSumProp(root->right);

     if(left.first == false || right.first==false) return {false,-1};
     if(left.second==-1 && right.second==-1) return {true,root->data};
     if(left.second==-1) left.second=0;
     if(right.second==-1) right.second=0;
     if((left.second+right.second)==root->data) return {true,root->data};
     else return {false,-1};
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(2);
    
    pair<bool,int> res = ChildrenSumProp(root);
    cout<<boolalpha<<res.first<<'\n';
    return 0;
}