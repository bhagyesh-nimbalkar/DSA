#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& adj,vector<int>& dis,vector<int>& low,stack<int>& st,int i,int parent){
     static int time = 0;
     dis[i] = low[i]= ++time;
     st.push(i);
     for(const auto& d:adj[i]){
        if(dis[d]==-1){
             dfs(adj,dis,low,st,d,i);
             low[i]=min(low[i],low[d]);
        }else if(d!=parent){
            low[i] = min(low[i],dis[d]);
        }
     }
     if(low[i]==dis[i]){
        while(!st.empty() && st.top()!=i){
            cout<<st.top()<<' ';
            st.pop();
        }
        cout<<st.top()<<' ';
        st.pop();
        cout<<'\n';
     }
}
void Tarjans(vector<vector<int>>& adj,int n){
    vector<int> dis(n,-1);
    vector<int> low(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(dis[i]==-1) dfs(adj,dis,low,st,i,-1);
    }
}
int main(){
    vector<vector<int>> adj(5);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    Tarjans(adj,5);
    return 0;
}