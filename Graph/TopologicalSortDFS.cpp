#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int>* adj,int x,stack<int>& st,vector<bool>& visited)
{
     visited[x]=true;
     for(int i=0;i<adj[x].size();i++)
     {
         if(!visited[adj[x][i]]) DFS(adj,adj[x][i],st,visited);
     }
     st.push(x);
}
void TSortDFS(vector<int>* adj,int size)
{
     stack<int> st;
     vector<bool> visited(size,0);
     for(int i=0;i<size;i++)
     {
         if(!visited[i]) DFS(adj,i,st,visited);
     }
     while(!st.empty()){
         cout<<st.top()<<' ';
         st.pop();
     }
     cout<<'\n';
}
int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    TSortDFS(adj,5);
    return 0;
}
