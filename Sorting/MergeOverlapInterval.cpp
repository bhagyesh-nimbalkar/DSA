#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> Merge(vector<pair<int,int>>& v)
{
       vector<pair<int,int>> ans;
       sort(v.begin(),v.end(),[](pair<int,int>& a,pair<int,int>& b){
                return a.first<b.first;
       });
       int flag=0;
       for(int i=1;i<v.size();i++)
       {
             int temp[4];
                   temp[0]=v[i-1].first;
                   temp[1]=v[i-1].second;
                   temp[2]=v[i].first;
                   temp[3]=v[i].second;
                   sort(temp,temp+4);
                   if(flag==1){
                      flag=0;
                      continue;
                   }
                   if(((temp[1]>=temp[0]) && (temp[1]<=temp[3])) && ((temp[2]>=temp[0]) && (temp[2]<=temp[3]))) 
                   {
                                 ans.emplace_back(temp[0],temp[3]);
                                 flag=1;
                   }
                   else
                   {
                    ans.emplace_back(v[i]);
                    flag=1;
                   }
       }
       return ans;
}
int main()
{
     vector<pair<int,int>> arr{{7,9},{6,10},{4,5},{1,3},{2,4}};
     vector<pair<int,int>> res = Merge(arr);
     for(int i=0;i<res.size();i++) cout<<res[i].first<<','<<res[i].second<<'\n';
     cout<<'\n';
     return 0;
}