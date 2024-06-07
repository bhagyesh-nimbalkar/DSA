#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<int>* adj,int source,vector<bool>& visited,vector<bool>& recur)
{
     visited[source]=true;
     recur[source]=true;

     for(int i=0;i<adj[source].size();i++)
     {
         if(visited[adj[source][i]] && recur[adj[source][i]]) return true;
         if(!visited[adj[source][i]]) {
            if(isCycle(adj,adj[source][i],visited,recur)==true) return true;
         }
     }
     recur[source]=false;
     return false;
}
bool DetectCycle(vector<int>* adj,int size)
{
     vector<bool> visited(size,false);
     vector<bool> Recur(size,false);
     for(int i=0;i<size;i++)
     {
      if(visited[i]==false)
      {
         bool res = isCycle(adj,i,visited,Recur);
         if(res) return true;
      }
     }
     return false;
}
int main(){
    vector<int> adj[4];
    adj[0].push_back(1);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(1);
    bool result = DetectCycle(adj,4);
    if(result) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}