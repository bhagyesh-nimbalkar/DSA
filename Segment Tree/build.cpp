#include <bits/stdc++.h>
using namespace std;

vector<int> t;
int buildSTree(vector<int>& v,int i,int j){
    if(i==j){
        t.push_back(v[i]);
        return v[i];
    }
    int mid = i+(j-i)/2;
    int res = buildSTree(v,i,mid) + buildSTree(v,mid+1,j);
    t.push_back(res);
    return res;
}
int main(){
    vector<int> v{10,20,30,40,50,60};
    buildSTree(v,0,v.size()-1);
    for(const auto& d:t) cout<<d<<' ';
    cout<<'\n';
    return 0;
}