#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int cchange(vector<int>& v,int Sum,int index){
    int res = 0;
    if(Sum==0) return 1;
    if(index>=v.size() || Sum<0) return 0;
    if(dp[Sum][index]!=-1) return dp[Sum][index];
    res+= cchange(v,Sum-v[index],index);
    res+= cchange(v,Sum,index+1);
    return dp[Sum][index] = res;
}
int main(){
    vector<int> coinType{2,5,6,3};
    int Sum = 10;
    dp.resize(Sum+1,vector<int>(coinType.size(),-1));
    cout<<cchange(coinType,Sum,0)<<'\n';
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++) cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}