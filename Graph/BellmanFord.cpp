#include <bits/stdc++.h>
using namespace std;

void BellmanFord(vector<vector<pair<int,int>>>& adj,int source){
    int v = adj.size();
    vector<int> dis(v,INT_MAX);
    dis[source]=0;
    for(int i=0;i<(v-1);i++){
        for(int j=0;j<v;j++){
            int source = j;
            for(const auto& d:adj[j]){
                int dest=d.first,weight=d.second;
                dis[dest] = min(dis[dest],dis[source]+weight);
            }
        }
    }
    for(int i=0;i<(v-1);i++){
        for(int j=0;j<v;j++){
            int source = j;
            for(const auto& d:adj[j]){
                int dest=d.first,weight=d.second;
                if(dis[dest]>(dis[source]+weight)){
                    cout<<"Negetive Cycle Detected.";
                }
            }
        }
    }
    for(int i=0;i<v;i++) cout<<dis[i]<<' ';
    cout<<'\n';
}

int main(){
    vector<vector<pair<int,int>>> adj(4);
    adj[0].push_back({1,1});
    adj[0].push_back({2,4});
    adj[1].push_back({2,-3});
    adj[1].push_back({3,2});
    adj[2].push_back({3,3});
    BellmanFord(adj,0);
    return 0;
}