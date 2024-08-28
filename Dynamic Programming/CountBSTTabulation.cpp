#include <bits/stdc++.h>
using namespace std;

int CB(int n){
    if(n==0 || n==1) return 1;
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    {
         dp[i]=0;
         for(int j=1;j<=i;j++){
              dp[i]+= (dp[j-1]*dp[i-j]);
         }
    }
    return dp[n];
}
int main(){
    cout<<CB(4)<<'\n';
    return 0;
}