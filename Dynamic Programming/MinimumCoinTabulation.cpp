#include <bits/stdc++.h>
using namespace std;


int MinCoin(vector<int>& v,int Val){
   vector<int> dp(Val+1,Val+1);
   dp[0]=0;
   for(int i=1;i<=Val;i++){
       for(int j=0;j<v.size();j++){
          if(v[j]<=i){
              dp[i] = min(dp[i],1+dp[i-v[j]]);
          }
       }
   }
   return (dp[Val]==(Val+1))?-1:dp[Val];
}
int main(){
    vector<int> v{9,6,1};
    int Sum = 11;
    cout<<MinCoin(v,Sum)<<'\n';
    return 0;
}