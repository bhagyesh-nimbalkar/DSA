#include <bits/stdc++.h>
using namespace std;

class DSU{
  private:
    int* parent;
    int* rank;
    int size;
  public:
     DSU(int x){
        parent = new int[x];
        rank = new int[x];
        for(int i=0;i<x;i++) {
            parent[i] =i;
            rank[i] = 0;
        }
        size=x;
     }
     int Find(int x)
     {
         if(parent[x]==x) return x;
         parent[x] = Find(parent[x]);
         return parent[x];
     }
     void Union(int x,int y)
     {
         int x_par = Find(x);
         int y_par = Find(y);

         if(x_par==y_par) return;

         if(rank[x_par]<rank[y_par]) parent[x_par] = y_par;
         else if(rank[y_par]<rank[x_par]) parent[y_par] = x_par;
         else parent[y_par]= x_par,rank[x_par]++;
     }
     void Display(){
        for(int i=0;i<size;i++) cout<<parent[i]<<' ';
        cout<<'\n';
     }
     ~DSU(){
        delete[] parent;
        delete[] rank;
     }
};
int main(){
     DSU obj(5);
     obj.Union(2,3);
     obj.Union(1,2);
     obj.Display();
     return 0;
}