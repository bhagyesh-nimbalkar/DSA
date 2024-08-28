#include <bits/stdc++.h>
using namespace std;

void DisplayFrequencies(vector<int>& v){
      unordered_map<int,int> m;
      for(int i=0;i<v.size();i++) m[v[i]]++;
      for(auto x:m)
      {
           cout<<x.first<<" "<<x.second<<'\n';
      }
}
int main()
{
     vector<int> v{10,20};
     DisplayFrequencies(v);
     return 0;
}