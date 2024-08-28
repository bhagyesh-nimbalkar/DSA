#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int Memo(vector<int>& v,int Sum,int index)
{
     if(Sum==0) return 1;
     if(index==0) return 0;
     if(dp[index][Sum]!=-1) return dp[index][Sum];
     int take=0,nottake=0;
     if(Sum>=v[index-1]) take = Memo(v,Sum-v[index-1],index-1);
     nottake = Memo(v,Sum,index-1);
     return dp[index][Sum] = take+nottake;
}
int findSubset(vector<int>& v,int Sum)
{
     dp.resize(v.size()+1,vector<int>(Sum+1,-1));
     return Memo(v,Sum,v.size());
}
int main(){
    vector<int> v{10,20,15};
    int Sum = 0;
    cout<<findSubset(v,Sum)<<'\n';
    return 0;
}