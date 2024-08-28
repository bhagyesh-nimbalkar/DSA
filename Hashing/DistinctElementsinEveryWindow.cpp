#include <bits/stdc++.h>
using namespace std;

vector<int> WindowDistinct(vector<int>& v,int k)
{
       unordered_map<int,int> m;
       vector<int> ans;
       for(int i=0;i<k;i++)
       { 
            m[v[i]]++;    
       }
       ans.emplace_back(m.size());
       for(int i=k;i<v.size();i++)
       {
              m[v[i-k]]--;
              if(m[v[i-k]]==0){ 
                m.erase(v[i-k]);
              }
              m[v[i]]++;

              ans.emplace_back(m.size());
       }
       return ans;
}
int main()
{
     vector<int> v{10,20,30,40};
     int k = 3;
     vector<int> res = WindowDistinct(v,k);
     for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
     cout<<'\n';
     return 0;
}