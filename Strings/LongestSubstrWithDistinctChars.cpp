#include <bits/stdc++.h>
using namespace std;

int LongestSubstr(string& x)
{
      vector<int> prev(256,-1);
      int res=0;
      int j=0;
      for(int i=0;i<x.size();i++)
      {
           j = max(j,prev[x[i]]+1);
           int MaxEnd = i-j+1;
           res = max(res,MaxEnd);
           prev[x[i]]=i;
      }
      return res;
}
int main()
{
     string str="aasgsgssagsede";
     cout<<LongestSubstr(str)<<'\n';
     return 0;
}