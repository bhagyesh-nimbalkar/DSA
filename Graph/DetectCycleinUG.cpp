#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<int>* adj,int source,int parent,vector<bool>& visited)
{
     visited[source]=true;
     for(int x:adj[source])
     {
          if(visited[x]==false)
          {
              if(isCycle(adj,x,source,visited)==true) return true;
          }
          else if(x!=parent) return true;
     }
     return false;
}
bool DetectCycle(int x,vector<int>* adj,int size)
{
     vector<bool> visited(size,false);
     return isCycle(adj,0,0,visited);
}
int main(){
    vector<int> adj[6];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    bool result = DetectCycle(0,adj,6);
    if(result) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}