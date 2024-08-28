#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int Memo(vector<int>& v,int index,int k){
    if(k==0){
        int Sum =0;
        for(int i=index;i<v.size();i++){
            Sum+=v[i];
        }
        return Sum;
    }
    if(index>=v.size()) return 0;
    if(dp[index][k]!=-1) return dp[index][k];
    int res = INT_MAX,Sum=0;
    for(int i=index;i<v.size();i++){
        Sum+=v[i];
        res = min(res,max(
            Sum,
            Memo(v,i+1,k-1)
        ));
    }
    return dp[index][k] = res;
}
int Page(vector<int>& v,int k){
    dp.resize(v.size(),vector<int>(k,-1));
    return Memo(v,0,k-1);
}
int main(){
    vector<int> v{10,5,30,1,2,5,10,10};
    int k=3;
    cout<<Page(v,k)<<'\n';
    return 0;
}