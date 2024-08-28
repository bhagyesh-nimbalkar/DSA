#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int editdistance(string& a,string& b,int m,int n){
   if(m==0) return dp[m][n]=n;
   if(n==0) return dp[m][n]=m;
   if(dp[m][n]!=-1) return dp[m][n];
   if(a[m-1]==b[n-1]) return dp[m][n] = editdistance(a,b,m-1,n-1);
   return dp[m][n] = 1+min({editdistance(a,b,m-1,n),editdistance(a,b,m-1,n-1),editdistance(a,b,m,n-1)});
}
int main(){
    string s1="saturday";
    string s2="sunday";
    dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
    cout<<editdistance(s1,s2,s1.size(),s2.size())<<'\n';
    return 0;
}