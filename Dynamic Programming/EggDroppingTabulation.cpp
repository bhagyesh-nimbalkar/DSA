#include <bits/stdc++.h>
using namespace std;


int EggDrop(int e,int f){
   if(e==1) return f;
   if(f==0) return 0;
   if(f==1) return 1;
   vector<vector<int>> dp(e+1,vector<int>(f+1,-1));
   for(int i=0;i<=e;i++){
       dp[0][i]=0;
       dp[1][i]=1;
   }
   for(int i=0;i<=f;i++) dp[1][i] = i;
   for(int i=2;i<=e;i++){
       for(int j=2;j<=f;j++){
            dp[i][j]=j;
            for(int k=1;k<=j;k++){
                dp[i][j] = min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);
            }
       }
   }
   return dp[e][f];
}
int main(){
    cout<<EggDrop(2,3)<<'\n';
    return 0;
}