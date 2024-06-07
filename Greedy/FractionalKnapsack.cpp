#include <bits/stdc++.h>
using namespace std;

int FKnapsack(vector<pair<int,int>>& data,int capacity)
{

     vector<pair<float,int>> ratio(data.size(),pair<float,int>());
     for(int i=0;i<data.size();i++)
     {
         ratio[i] = {(float)data[i].second/data[i].first,i};
     }
     sort(ratio.begin(),ratio.end(),[](pair<float,int>& a,pair<float,int>& b){
        return a.first>b.first;
     });
     int result= 0;
     for(int i=0;i<data.size();i++)
     {
         int index =ratio[i].second; 
         if(data[index].first<=capacity)
         {
               capacity-=data[index].first;
               result+=data[index].second;
         }
         else{
               result+=(data[index].second*capacity)/data[index].first;
         }
     }
     return result;
}
int main()
{
    vector<pair<int,int>> v{{30,120},{20,100},{10,60}};
    cout<<FKnapsack(v,50)<<'\n';
    return 0;
}