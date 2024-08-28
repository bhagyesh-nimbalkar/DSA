#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int EggDrop(int e,int f){
    if(f==0) return 0;
    if(e==1) return f;
    if(f==1) return 1;
    if(dp[e][f]!=-1) return dp[e][f];
    int res = f;
    for(int i=1;i<=f;i++)
    {
        res = min(res,max(EggDrop(e-1,i-1),EggDrop(e,f-i))+1);
    }
    return dp[e][f] = res;
}
int main(){
    dp.resize(8,vector<int>(101,-1));
    cout<<EggDrop(2,20)<<'\n';
    return 0;
}