#include <bits/stdc++.h>
using namespace std;

int LCS(string& a,string& b){
    int m = a.size(),n=b.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout<<LCS(a,b)<<'\n';
    return 0;
}