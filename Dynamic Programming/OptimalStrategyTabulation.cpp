#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int Optimal(vector<int>& v){
    dp.resize(v.size(),vector<int>(v.size(),-1));
}
int main(){
    vector<int> v{20,5,4,6};
    cout<<Optimal(v)<<'\n';
    return 0;
}