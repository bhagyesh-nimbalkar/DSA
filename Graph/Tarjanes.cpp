#include <bits/stdc++.h>
using namespace std;

void SCC(int u,vector<int>* adj,vector<int>& disc,vector<int>& low,stack<int>& st,vector<bool>& vis)
{
     static int time=0;
     disc[u]=low[u] = ++time;
     vis[u]=true;
     st.push(u);
     for(int i=0;i<adj[u].size();i++)
     {
          int v = adj[u][i];
          if(disc[v]==-1)
          {
            SCC(v,adj,disc,low,st,vis);
            low[u] = min(low[u],low[v]);
          }
          else if(vis[v])
          {
              low[u] = min(low[u],disc[v]);
          }
     }
     if(disc[u]==low[u])
     {
         while(!st.empty() && low[st.top()]==low[u])
         {
             cout<<st.top()<<' ';
             vis[st.top()]=false;
             st.pop();
         }
         cout<<'\n';
     }
}
void Tarjanes(vector<int>* adj,int n)
{
     vector<int> disc(n,-1);
     vector<int> low(n,INT_MAX);
     vector<bool> vis(n,false);
     stack<int> st;
     for(int i=0;i<n;i++)
     {
         if(disc[i] == -1){
            SCC(i,adj,disc,low,st,vis);
         }
     }
}
int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(2);
    Tarjanes(adj,5);
    return 0;
}