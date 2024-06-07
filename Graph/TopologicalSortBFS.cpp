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
void TSort(vector<int>* adj,int size)
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
     while(!q.empty())
     {
         int x = q.front();
         q.pop();
         indegree[x]=-1;
         cout<<x<<' ';
         Reduce(indegree,x,adj,q);
     }
}
int main(){
     vector<int> adj[5];
     adj[0].push_back(2);
     adj[0].push_back(3);
     adj[1].push_back(3);
     adj[1].push_back(4);
     adj[2].push_back(3);
     TSort(adj,5);
     cout<<'\n';
     return 0;
}