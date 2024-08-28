#include <bits/stdc++.h>
using namespace std;


int MST(vector<pair<int,int>>* adj,int n)
{
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0,0});
     vector<bool> vis(n,false);
     vis[0]=true;
     int Sum=0;
     while(!pq.empty())
     {
          pair<int,int> top = pq.top();
          int w=top.first,v=top.second;
          Sum+=w;
          pq.pop();
          for(const auto& [node,weight]:adj[v])
          {
              if(!vis[node]){
                vis[node]=true;
                pq.push({weight,node});
              }
          }
     }
     return Sum;
}
int main()
{
    vector<pair<int,int>> adj[5];
    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[1].push_back({2,3});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});
    cout<<MST(adj,5)<<'\n';
    return 0;
}