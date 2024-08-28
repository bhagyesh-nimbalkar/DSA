#include <bits/stdc++.h>
using namespace std;

int MaxProfit(vector<int>& p,vector<int>& w,int c){
    vector<vector<int>> dp;
    dp.resize(p.size()+1,vector<int>(c+1,0));
    for(int i=1;i<=p.size();i++){
        for(int j=1;j<=c;j++){
            if(w[i-1]>j) dp[i][j] = max(dp[i][j],dp[i-1][j]);
            else dp[i][j] = max(dp[i-1][j],p[i-1] + dp[i-1][j-w[i-1]]);
        }
    }
    return dp[p.size()][c];
}
int main(){
    vector<int> val{60,100,120};
    vector<int> weight{10,20,30};
    int capacity=50;
    cout<<MaxProfit(val,weight,capacity)<<'\n';
    return 0;
}