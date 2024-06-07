#include <bits/stdc++.h>
using namespace std;


int MST(vector<pair<int,int>>* adj,int n)
{
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0,0});
     int res = 0;
     vector<bool> vis(n,false);
     vector<int> Key(n,INT_MAX);
     Key[0]=0;
     for(int i=0;i<n;i++)
     {
         int Min = pq.top().second;
         cout<<Min<<" "<<pq.top().first<<'\n';
         res = res+ pq.top().first;
         pq.pop();
         vis[Min]=true;
         for(int j=0;j<adj[Min].size();j++)
         {
             if(!vis[adj[Min][j].second])
             {
                 Key[adj[Min][j].second] = min(adj[Min][j].first,Key[adj[Min][j].second]);
                 stack<pair<int,int>> st;
                 while(!pq.empty())
                 {
                     pair<int,int> Top = pq.top();
                     if(Top.second == adj[Min][j].second)
                     {
                         pq.pop();
                         break;
                     }
                     pq.pop();
                     st.push(Top);
                 }
                 pq.push({Key[adj[Min][j].second],adj[Min][j].second});
                 while(!st.empty())
                 {
                     pq.push(st.top());
                     st.pop();
                 }
             }
         }
        //  for(int j=0;j<n;j++) cout<<Key[j]<<' ';
        //  cout<<'\n';
     }
     return res;
}
int main()
{
    vector<pair<int,int>> adj[5];
    adj[0].push_back({2,1});
    adj[0].push_back({6,3});
    adj[1].push_back({2,0});
    adj[1].push_back({3,2});
    adj[1].push_back({8,3});
    adj[1].push_back({5,4});
    adj[2].push_back({3,1});
    adj[2].push_back({7,4});
    adj[3].push_back({6,0});
    adj[3].push_back({8,1});
    adj[3].push_back({9,4});
    adj[4].push_back({9,3});
    adj[4].push_back({5,1});
    adj[4].push_back({7,2});
    cout<<MST(adj,5)<<'\n';
    return 0;
}