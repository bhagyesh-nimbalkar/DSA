#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int find(string& a,string& b,int m,int n){
    if(m==0 || n==0) return 0;
    if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
    if(a[m-1]==b[n-1]) return dp[m-1][n-1] =  1+find(a,b,m-1,n-1);
    else return dp[m-1][n-1] =  max(find(a,b,m-1,n),find(a,b,m,n-1));
}
int LCS(string& a,string& b){
    return find(a,b,a.size(),b.size());
}
int main(){
    string s1="AGGTAB";
    string s2="GXTXAYB";
    dp.resize(s1.size(),vector<int>(s2.size(),-1));
    cout<<LCS(s1,s2)<<'\n';
    return 0;
}