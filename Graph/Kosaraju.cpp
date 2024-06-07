#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<int>* adj,stack<int>& st,vector<bool>& vis,int source)
{
     vis[source]=true;
     for(int i=0;i<adj[source].size();i++)
     {
         if(!vis[adj[source][i]]) DFSRec(adj,st,vis,adj[source][i]);
     }
     st.push(source);
}
vector<int> getOrder(vector<int>* adj,int n)
{
     stack<int> st;
     vector<bool> vis(n,false);
     for(int i=0;i<n;i++)
     {
        if(!vis[i])
          DFSRec(adj,st,vis,i);
     }
     vector<int> res;
     while(!st.empty())
     {
         res.emplace_back(st.top());
         st.pop();
     }
     return res;
}
void dfs(vector<int>* adj,int s,vector<bool>& vis)
{
     vis[s]=true;
     cout<<s<<' ';
     for(int i=0;i<adj[s].size();i++)
     {
         if(!vis[adj[s][i]]) dfs(adj,adj[s][i],vis);
     }
}
void Kosaraju(vector<int>* adj,int n)
{
     vector<int> res = getOrder(adj,n);
     vector<int> transpose[n];
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<adj[i].size();j++)
         {
              transpose[adj[i][j]].push_back(i);
         }
     }
     vector<bool> vis(n,false);
     for(int i=0;i<n;i++)
     {
         if(vis[i]) continue;
         vis[i]=true;
         cout<<i<<' ';
         for(int j=0;j<transpose[i].size();j++)
         {
              if(!vis[transpose[i][j]]) dfs(transpose,transpose[i][j],vis);
         }
         cout<<'\n';
     }
}
int main(){
    vector<int> adj[4];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(0);
    Kosaraju(adj,4);
    return 0;
}