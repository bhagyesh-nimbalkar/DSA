#include <bits/stdc++.h>
using namespace std;

void SortKSorted(vector<int>& v,int k)
{
     priority_queue<int,vector<int>,greater<int>> pq;
     for(int i=0;i<=k;i++)
     {
         pq.push(v[i]);
     }
     int i=0;
     while(!pq.empty() && (k+i+1)<v.size())
     {
          v[i]=pq.top();
          pq.pop();
          pq.push(v[k+i+1]);
          i++;
     }
     while(!pq.empty())
     {
         v[i]=pq.top();
         pq.pop();
         i++;
     }
}
int main()
{
    vector<int> v{10,9,7,8,4,70,50,60};
    SortKSorted(v,4);
    for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
    cout<<'\n';
    return 0;
}