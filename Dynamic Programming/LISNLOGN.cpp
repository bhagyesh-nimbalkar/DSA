#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v){
    if(v.size()==0) return -1;
    vector<int> temp;
    temp.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        if(v[i]>temp.back()) temp.push_back(v[i]);
        else{
            int idx = lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin();
            temp[idx] = v[i];
        }
    }
    return temp.size();
}
int main(){
    vector<int> v{3,4,2,8,10,5,1};
    cout<<LIS(v)<<'\n';
    return 0;
}