#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int Memo(vector<int>& v,int i,int j){
    if((i+1)==j) return max(v[i],v[j]);
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = max(
        v[i] + min(
            Memo(v,i+2,j),
            Memo(v,i+1,j-1)
        ),
        v[j]+min(
            Memo(v,i+1,j-1),
            Memo(v,i,j-2)
        )
    );
}
int Optimal(vector<int>& v){
    dp.resize(v.size(),vector<int>(v.size(),-1));
    return Memo(v,0,v.size()-1);
}
int main(){
    vector<int> v{20,5,4,6};
    cout<<Optimal(v)<<'\n';
    return 0;
}