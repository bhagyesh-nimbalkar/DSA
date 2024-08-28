#include <bits/stdc++.h>
using namespace std;

int FindSum(vector<int>& v)
{
    if(v.size()==1) return v[0];
    if(v.size()==2) return max(v[0],v[1]);
    v[1] = max(v[0],v[1]);
    for(int i=2;i<v.size();i++){
        v[i] = max(v[i-1],v[i]+v[i-2]);
    }
    return v[v.size()-1];
}
int main(){
    vector<int> v{10,5,15,20};
    cout<<FindSum(v)<<'\n';
    return 0;
}