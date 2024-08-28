#include <bits/stdc++.h>
using namespace std;
int editdistance(string& a,string& b){
    vector<vector<int>> dp(b.size()+1,vector<int>(a.size()+1,0));
    for(int i=0;i<=a.size();i++) dp[0][i] = i;
    for(int i=0;i<=b.size();i++) dp[i][0] = i;
    for(int i=1;i<=b.size();i++){
        for(int j=1;j<=a.size();j++){
            if(b[i-1]==a[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    return dp[b.size()][a.size()];
}
int main(){
    string s1="cut";
    string s2="cat";
    cout<<editdistance(s1,s2)<<'\n';
    return 0;
}