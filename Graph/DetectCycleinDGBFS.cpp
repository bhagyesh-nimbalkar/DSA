#include <bits/stdc++.h>
using namespace std;


void Reduce(vector<int>& indegree,int x,vector<int>* adj,queue<int>& q)
{ 
     for(int i=0;i<adj[x].size();i++)
     {
         if(indegree[adj[x][i]]==-1) continue;
         indegree[adj[x][i]]--;
         if(indegree[adj[x][i]]==0){
            q.push(adj[x][i]);
         }
     }
}
bool TSort(vector<int>* adj,int size)
{
     vector<int> indegree(size,0);
     for(int i=0;i<size;i++)
     {
         for(int j=0;j<adj[i].size();j++)
         { 
             indegree[adj[i][j]]++;
         }
     }
     queue<int> q;
     for(int i=0;i<size;i++)
     { 
         if(indegree[i]==0) q.push(i);
     }
     int cnt=0;
     while(!q.empty())
     {
         int x = q.front();
         q.pop();
         cnt++;
         indegree[x]=-1;
         Reduce(indegree,x,adj,q);
     }
     return cnt==size;
}
int main(){
     vector<int> adj[5];
     adj[0].push_back(1);
     adj[1].push_back(2);
     adj[2].push_back(3);
     adj[3].push_back(1);
     adj[4].push_back(1);
     bool result = TSort(adj,5);
     if(result) cout<<"NO\n";
     else cout<<"YES\n";
     return 0;
}