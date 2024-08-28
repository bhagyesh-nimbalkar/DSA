#include <bits/stdc++.h>
using namespace std;

int MaxCuts(int n,int a,int b,int c)
{
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        int res = -1;
        if(a<=i) res = (dp[i-a]==-1)?-1:max(res,1+dp[i-a]);
        if(b<=i) res = (dp[i-b]==-1)?-1:max(res,1+dp[i-b]);
        if(c<=i) res = (dp[i-c]==-1)?-1:max(res,1+dp[i-c]);
        dp[i]=res;
    }
    return dp[n];
}
int main(){
    int n=23,a=11,b=13,c=12;
    cout<<MaxCuts(n,a,b,c)<<'\n';
    return 0;
}