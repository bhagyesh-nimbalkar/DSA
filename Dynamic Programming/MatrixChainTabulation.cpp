#include <bits/stdc++.h>
using namespace std;


int Find(vector<int>& v){
    vector<vector<int>> dp(v.size(),vector<int>(v.size(),0));
    for(int gap=2;gap<v.size();gap++){
        for(int i=0;i+gap<v.size();i++){
            int j=i+gap;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j] = min(dp[i][j],(
                     dp[i][k]+
                     dp[k][j]+
                     v[i]*v[j]*v[k]
                ));
            }
        }
    }
    return dp[0][v.size()-1];
}
int main(){
    vector<int> v{2,1,3,4};
    cout<<Find(v)<<'\n';
    return 0;
}