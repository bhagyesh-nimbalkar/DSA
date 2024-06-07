#include <bits/stdc++.h>
using namespace std;

void printDFS(vector<int>* adj,int s,vector<bool>& visited)
{
     visited[s]=true;
     cout<<s<<' ';
     for(int i=0;i<adj[s].size();i++){
       if(visited[adj[s][i]]==false) printDFS(adj,adj[s][i],visited);
     }
}
void GraphDFS(vector<int>* adj,int size,int s)
{
     vector<bool> visited(size,false);
     printDFS(adj,s,visited);
     cout<<'\n';
}
int main()
{
    vector<int> adj[7];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(4);
    GraphDFS(adj,6,0);
    return 0;
}