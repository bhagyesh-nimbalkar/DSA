#include <bits/stdc++.h>
using namespace std;

class DSU{
    private:
      int n;
      vector<int> parent,rank;
    public:
      DSU(int x){
        n=x;
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
      }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int x_r = find(x);
        int y_r = find(y);
        if(rank[x_r]<rank[y_r]) parent[x_r] = y_r;
        else if(rank[x_r]>rank[y_r]) parent[y_r] = x_r;
        else{
            parent[y_r] = x_r;
            rank[x_r]++;
        }
    }
};
int main(){
    
}