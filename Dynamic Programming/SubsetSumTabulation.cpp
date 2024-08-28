#include <bits/stdc++.h>
using namespace std;

int findSubset(vector<int>& v,int Sum)
{
     vector<vector<int>> dp(v.size()+1,vector<int>(Sum+1,0));
     for(int i=0;i<=v.size();i++) dp[i][0]=1;
     for(int i=1;i<=v.size();i++){
        for(int j=1;j<=Sum;j++){
            if(j>=v[i-1]){
                dp[i][j] = dp[i-1][j-v[i-1]];
            }
            dp[i][j] += dp[i-1][j];
        }
     }
     return dp[v.size()][Sum];
}
int main(){
    vector<int> v{2,5,3};
    int Sum = 5;
    cout<<findSubset(v,Sum)<<'\n';
    return 0;
}