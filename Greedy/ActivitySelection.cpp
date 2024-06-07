#include <bits/stdc++.h>
using namespace std;

int selectAct(vector<pair<int,int>>& v)
{
     sort(v.begin(),v.end(),[](pair<int,int>& a,pair<int,int>& b){
        return a.second<b.second;
     });
     int cnt=1;
     pair<int,int> prev = v[0];
     for(int i=1;i<v.size();i++)
     {
         if(v[i].first>=prev.second){
            cnt++;
            prev=v[i];
         }
     }
     return cnt;
}
int main(){
     vector<pair<int,int>> v{{3,8},{2,4},{1,3},{10,11}};
     cout<<selectAct(v)<<'\n';
     return 0;
}