#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& list,int u,int v)
{
     list[u].push_back(v);
     list[v].push_back(u);
}
void printGraph(vector<vector<int>>& list)
{
     for(int i=0;i<list.size();i++)
     {
         for(auto d:list[i]){
            cout<<d<<' ';
         }
         cout<<'\n';
     }
}
int main()
{
     vector<vector<int>> list;
     list.resize(4,vector<int>());
     addEdge(list,0,1);
     addEdge(list,2,0);
     printGraph(list);
     return 0;
}