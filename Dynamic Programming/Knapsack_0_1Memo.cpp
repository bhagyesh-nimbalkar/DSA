#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int Memo(vector<int>& p,vector<int>& w,int c,int index){
    if(index==0) return 0;
    if(dp[index][c]!=-1) return dp[index][c];
    int take=0,nottake=0;
    if(c>=w[index-1]){
        take = p[index-1]+Memo(p,w,c-w[index-1],index-1);
    }
    nottake = Memo(p,w,c,index-1);

    return dp[index][c] = max(take,nottake);
}
int MaxProfit(vector<int>& p,vector<int>& w,int c){
    dp.resize(p.size()+1,vector<int>(c+1,-1));
    return Memo(p,w,c,p.size());
}
int main(){
    vector<int> val{10,40,30,50};
    vector<int> weight{5,4,6,3};
    int capacity=10;
    cout<<MaxProfit(val,weight,capacity)<<'\n';
    return 0;
}