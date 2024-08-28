#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& v,int index,vector<int>& dp)
{
      if(index<0) return 0;
      if(dp[index]!=-1) return dp[index];
      int take=0,nottake=0;
      take = v[index]+dfs(v,index-2,dp);
      nottake=dfs(v,index-1,dp);
      return dp[index] = max(take,nottake);
}
int FindSum(vector<int>& v)
{
     vector<int> dp(v.size(),-1);
     return dfs(v,v.size()-1,dp);
}
int main(){
    vector<int> v{8,7,6,10};
    cout<<FindSum(v)<<'\n';
    return 0;
}