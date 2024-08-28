#include <bits/stdc++.h>
using namespace std;

void MorethenNByK(vector<int>& v,int k)
{
      unordered_map<int,int> m;
      for(int i=0;i<v.size();i++) m[v[i]]++;

      for(auto x:m)
      { 
           if(x.second>(v.size()/k)) cout<<x.first<<" ";
      }
      cout<<'\n';
      return;
}
int main()
{
      vector<int> v{30,10,20,30,30,40,30,40,30};
      int k = 2;
      MorethenNByK(v,k);
      return 0;
}