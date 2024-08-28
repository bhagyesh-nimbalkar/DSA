#include <bits/stdc++.h>
using namespace std;


void findAP(int i,vector<int>* adj,vector<int>& parent,vector<int>& disc,vector<int>& low,vector<bool>& ap,vector<bool>& vis)
{
     static int time = 0;
     vis[i]=true;
     int children = 0;
     disc[i]=low[i]=++time;

     for(int j=0;j<adj[i].size();j++)
     {
          if(!vis[adj[i][j]])
          {
             ++children;
             parent[adj[i][j]]=i;
             findAP(adj[i][j],adj,parent,disc,low,ap,vis);

             low[i] = min(low[i],low[adj[i][j]]);

             if(parent[i]==-1 && children>1) ap[i]=true;
             if(parent[i]!=-1 && low[adj[i][j]]>=disc[i]) ap[i]=true;
          }
          else if(adj[i][j]!=parent[i])
          {
              low[i] = min(low[i],disc[adj[i][j]]);
          }
     }
}
void ArticulationPoints(vector<int>* adj,int n)
{
     vector<bool> vis(n,false);
     vector<int>  disc(n,0);
     vector<int>  low(n,INT_MAX);
     vector<int> parent(n,-1);
     vector<bool> ap(n,false);
     for(int i=0;i<n;i++)
     {
         if(!vis[i]) findAP(i,adj,parent,disc,low,ap,vis);
     }
     for(int i=0;i<n;i++){
         if(ap[i]) cout<<i<<' ';
     }
     cout<<'\n';
}
int main(){
    vector<int> adj[5];
    adj[1].push_back(0);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    ArticulationPoints(adj,5);
    return 0;
}