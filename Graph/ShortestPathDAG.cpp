#include <bits/stdc++.h>
using namespace std;

void ShortestPath(vector<vector<pair<int,int>>>& adj,int source)
{ 
     vector<int> indegree(adj.size(),0);
     for(const auto& d:adj){
         for(const auto& [v,w]:d){
            indegree[v]++;
         }
     }
     vector<int> dp(adj.size(),INT_MAX);
     queue<int> q;
     q.push(source);
     dp[source]=0;
     while(!q.empty())
     {
         int x = q.front();
         indegree[x]=-1;
         q.pop();
         for(auto& [n,dist]:adj[x]){
            dp[n] = min(dp[n],dp[x]+dist);
            indegree[n]--;
            if(indegree[n]==0) q.push(n);
         }
     }
     for(int i=0;i<dp.size();i++){
         cout<<dp[i]<<' ';
     }
     cout<<'\n';
}
int main(){
     int size=4;
     vector<vector<pair<int,int>>> adj(size);
     adj[0].push_back({1,1});
     adj[1].push_back({2,3});
     adj[1].push_back({3,2});
     adj[2].push_back({3,4});
     ShortestPath(adj,1);
     return 0;
}