#include <bits/stdc++.h>
using namespace std;

int Summation(vector<int>& v,int i,int j){
    int Sum = 0;
    for(int k=i;k<=j;k++) Sum+=v[k];
    return Sum;
}
int Page(vector<int>& v,int k){
    vector<vector<int>> dp(k+1,vector<int>(v.size()+1,0));
    int Sum = 0;
    for(int i=1;i<v.size();i++){
        Sum+=v[i-1];
        dp[1][i]=Sum;
    }
    for(int i=1;i<=k;i++){
         dp[i][1] = v[0];
    }

    for(int i=2;i<=k;i++){
        for(int j=2;j<=v.size();j++){
            int res = INT_MAX;
            for(int p=1;p<j;p++){
                res = min(res,max(
                    dp[i-1][p],
                    Summation(v,p,j-1)
                ));
            }
            dp[i][j]=res;
        }
    }
    return dp[k][v.size()];
}
int main(){
    vector<int> v{10,20,30,40};
    int k=2;
    cout<<Page(v,k)<<'\n';
    return 0;
}