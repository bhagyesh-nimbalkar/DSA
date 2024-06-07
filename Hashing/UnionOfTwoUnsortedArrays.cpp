#include <bits/stdc++.h>
using namespace std;
int Distinct(vector<int>& a,vector<int>& b)
{  
      unordered_set<int> s(a.begin(),a.end());
      for(int i=0;i<b.size();i++) s.insert(b[i]);

      return s.size();
}
int main()
{
     vector<int> a{3,3,3};
     vector<int> b{3,3};
     cout<<Distinct(a,b)<<'\n';
     return 0;
}