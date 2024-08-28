#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int CB(int n){
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int Sum = 0;
    for(int i=1;i<=n;i++){
        Sum += (CB(i-1)*CB(n-i));
    }
    return dp[n] = Sum;
}
int main(){
    dp.resize(6,-1);
    cout<<CB(5)<<'\n';
    return 0;
}