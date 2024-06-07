#include <bits/stdc++.h>
using namespace std;

struct Node{
     int val;
     Node* left,*right;
     Node(int x):val{x},left{nullptr},right{nullptr}{}
};
void CeilLeft(vector<int>& v)
{
     set<int> s;
     for(int i=0;i<v.size();i++)
     {
          auto res = s.lower_bound(v[i]);
          if(res==s.end())
          {
                 cout<<-1<<'\n';
          }
          else {
              cout<<*res<<'\n';
          }
          s.insert(v[i]);
     }
}
int main(){
     vector<int> v = {2,8,30,15,25,12};
     CeilLeft(v);
     return 0;
}