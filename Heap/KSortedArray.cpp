#include <bits/stdc++.h>
using namespace std;

vector<int> KSort(vector<vector<int>>& mat)
{
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
     vector<int> res;
     for(int i=0;i<mat.size();i++)
     {
         pq.push(make_pair(mat[i][0],make_pair(i,0)));
     }
     while(!pq.empty())
     {
         res.emplace_back(pq.top().first);
         int i=pq.top().second.first;
         int j = pq.top().second.second;
         pq.pop();
         j++;
         if(j<mat[i].size())
         {
             pq.push(make_pair(mat[i][j],make_pair(i,j)));
         }
     }
     return res;
}
int main(){
     vector<vector<int>> v{{5,20,30},{1,2}};
     vector<int> res = KSort(v);
     for(int i=0;i<res.size();i++) cout<<res[i]<<' ';
     cout<<'\n';
     return 0;
}