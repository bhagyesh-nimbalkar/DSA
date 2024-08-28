#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v{3,4,2,8,10,5,1};
    vector<int> dp(v.size(),1);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<'\n';
    return 0;
} 