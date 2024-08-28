#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string& str,int i,int j){
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++,j--;
    }
    return true;
}
int PP(string& str){
   vector<vector<int>> dp(str.size(),vector<int>(str.size(),0));
    for(int gap=1;gap<str.size();gap++){
        for(int i=0;i+gap<str.size();i++){
          int j=i+gap;
          if(isPallindrome(str,i,j)){
            dp[i][j]=0;
            continue;
          }
          dp[i][j]=INT_MAX;
          for(int k=i;k<j;k++)
          {
                dp[i][j] = min(dp[i][j],(
                    dp[i][k]+
                    dp[k+1][j]+1
                ));
          }
        }
    }
    return dp[0][str.size()-1];
}
int main(){
    string str="aaaa";
    cout<<PP(str)<<'\n';
    return 0;
}