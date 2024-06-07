#include <bits/stdc++.h>
using namespace std;


vector<int> MinimumCount(vector<int>* adj,int size,int s)
{
     vector<int> dist(size,0);
     for(int i=0;i<size;i++)
     {
         if(i==s) dist[i]=0;
         else dist[i]=INT_MAX;
     }
     vector<bool> visited(size,false);
     queue<int> q;
     q.push(s);
     visited[s]=true;
     while(!q.empty())
     { 
         int u = q.front();
         visited[u]=true;
         for(int v:adj[u])
         {
              if(visited[v]==false)
              {
                 dist[v]= min(dist[v],dist[u]+1);
                 q.push(v);
              }
         }
         q.pop();
     }
     return dist;
}
int main(){
    vector<int> adj[6];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(4);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(0);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[5].push_back(4);
    vector<int> result = MinimumCount(adj,6,0);
    for(int i=0;i<result.size();i++) cout<<result[i]<<' ';
    cout<<'\n';
    return 0;
}