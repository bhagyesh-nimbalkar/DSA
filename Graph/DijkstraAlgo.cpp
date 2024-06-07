#include <bits/stdc++.h>
using namespace std;


void Dijkstra(vector<pair<int,int>>* adj,int n,int source)
{
     vector<int> Key(n,INT_MAX);
     Key[source]=0;
     vector<bool> vis(n,false);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     for(int i=0;i<n;i++)
     {
         pq.push({Key[i],i});
     }
     while(!pq.empty())
     { 
         while(!pq.empty() && vis[pq.top().second])
         {
             pq.pop();
         }
         if(pq.size()==0) break;
         pair<int,int> Top = pq.top();
         pq.pop();
         vis[Top.second]=true;
         for(int j=0;j<adj[Top.second].size();j++)
         {
             if(!vis[adj[Top.second][j].second])
             {
                 if((Top.first+adj[Top.second][j].first)<Key[adj[Top.second][j].second])
                 {
                       Key[adj[Top.second][j].second]=Top.first+adj[Top.second][j].first;
                       pq.push({Key[adj[Top.second][j].second],adj[Top.second][j].second});
                 }
             }
         }
     }
     for(int i=0,j='A';i<n;i++,j++)
     {
         cout<<(char)j<<' '<<Key[i]<<'\n';
     }
}
int main(){
    vector<pair<int,int>> adj[3];
    adj[0].push_back({5,1});
    adj[0].push_back({3,2});
    adj[1].push_back({5,0});
    adj[1].push_back({1,2});
    adj[2].push_back({3,0});
    adj[2].push_back({1,1});
    Dijkstra(adj,3,0);
    return 0;
}