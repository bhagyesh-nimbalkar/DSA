#include <bits/stdc++.h>
using namespace std;

vector<int> Kclosest(vector<int>& v,int x,int k)
{
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     vector<int> ans;
     for(int i=0;i<v.size();i++)
     {
           pq.push(make_pair(abs(v[i]-x),v[i]));
     }
     for(int i=0;i<k;i++){
          ans.emplace_back(pq.top().second);
          pq.pop();
     }
     return ans;
}
int main(){
     vector<int> v{30,40,32,33,36,37};
     vector<int> res = Kclosest(v,38,3);
     for(int i=0;i<res.size();i++) cout<<res[i]<<' ';
     cout<<'\n';
     return 0;
}