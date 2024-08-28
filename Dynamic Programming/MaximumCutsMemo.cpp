#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int MaxCuts(int n,int& a,int& b,int& c)
{
    if(n==0) return 0;
    if(n<0) return -1;
    if(dp[n]!=-10) return dp[n];
    int res = max({
        MaxCuts(n-a,a,b,c),
        MaxCuts(n-b,a,b,c),
        MaxCuts(n-c,a,b,c),
                    });
    if(res<0) return dp[n] =  -1;
    return dp[n] = res+1;
}
int main(){
    int n=23,a=11,b=12,c=13;
    dp.resize(n+1,-10);
    cout<<MaxCuts(n,a,b,c)<<'\n';
    return 0;
}