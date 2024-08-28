#include <bits/stdc++.h>
using namespace std;


void Dijkstra(vector<pair<int,int>>* adj,int n,int source)
{
     vector<int> dis(n,INT_MAX);
     vector<bool> vis(n,false);
     dis[source]=0;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     for(int i=0;i<n;i++){
         pq.push({dis[i],i});
     }
     while(!pq.empty()){
         while(!pq.empty() && vis[pq.top().second]){
            pq.pop();
         }
         if(pq.empty()) break;
         pair<int,int> Top = pq.top();
         pq.pop();
         vis[Top.second]=true;
         for(const auto& d:adj[Top.second]){
            if(!vis[d.first]){
                dis[d.first] = min(dis[d.first],Top.first+d.second);
                pq.push({dis[d.first],d.first});
            }
         }
     }
     for(char i='A';i<'A'+n;i++){
        cout<<i<<" "<<dis[i-'A']<<'\n';
     }
}
int main(){
    vector<pair<int,int>> adj[9];
    adj[0].push_back({1,4});
    adj[0].push_back({2,8});
    adj[1].push_back({0,4});
    adj[1].push_back({2,11});
    adj[1].push_back({3,8});
    adj[2].push_back({0,8});
    adj[2].push_back({1,11});
    adj[2].push_back({4,7});
    adj[2].push_back({5,1});
    adj[3].push_back({1,8});
    adj[3].push_back({4,2});
    adj[3].push_back({6,7});
    adj[3].push_back({7,4});
    adj[4].push_back({3,2});
    adj[4].push_back({2,7});
    adj[4].push_back({5,6});
    adj[5].push_back({2,1});
    adj[5].push_back({4,6});
    adj[5].push_back({7,2});
    adj[6].push_back({3,7});
    adj[6].push_back({7,14});
    adj[6].push_back({8,9});
    adj[7].push_back({5,2});
    adj[7].push_back({3,4});
    adj[7].push_back({6,14});
    adj[7].push_back({8,10});
    adj[8].push_back({6,9});
    adj[8].push_back({7,10});
    Dijkstra(adj,9,0);
    return 0;
}