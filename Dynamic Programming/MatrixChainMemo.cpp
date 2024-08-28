#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int Memo(vector<int>& v,int i,int j)
{
     if((i+1)==j) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int res = INT_MAX;
     for(int k=i+1;k<j;k++){
        res = min(res,(
          Memo(v,i,k)+
          Memo(v,k,j)+
          v[i]*v[k]*v[j]
        ));
     }
     return dp[i][j] = res;
}
int Find(vector<int>& v){
    dp.resize(v.size(),vector<int>(v.size(),-1));
    return Memo(v,0,v.size()-1);
}
int main(){
    vector<int> v{2,1,3,4};
    cout<<Find(v)<<'\n';
    return 0;
}