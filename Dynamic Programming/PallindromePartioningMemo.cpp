#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string& str,int i,int j){
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++,j--;
    }
    return true;
}
vector<vector<int>> dp;
int Memo(string& str,int i,int j){
    if(isPallindrome(str,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res = INT_MAX;
    for(int k=i;k<j;k++){
        res = min(res,(
            Memo(str,i,k)+
            Memo(str,k+1,j)+1
        ));
    }
    return dp[i][j] = res;
}
int PP(string& str){
    dp.resize(str.size(),vector<int>(str.size(),-1));
    return Memo(str,0,str.size()-1);
}
int main(){
    string str="abcde";
    cout<<PP(str)<<'\n';
    return 0;
}