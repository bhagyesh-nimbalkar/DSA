#include <bits/stdc++.h>
using namespace std;

int LargestArea(vector<int>& v)
{
     vector<int> arr1(v.size(),0);
     vector<int> arr2(v.size(),0);

     arr1[0]=-1;
     for(int i=1;i<v.size();i++)
     { 
         int k = i-1;
         while(k!=-1 && v[k]>=v[i])
         {
              k=arr1[k];
         }
         arr1[i]=k;
     }
     arr2[v.size()-1]=-1;
     for(int i=v.size()-2;i>=0;i--)
     {
          int k = i+1;
         while(k!=-1 && v[k]>=v[i])
         {
              k=arr2[k];
         }
         arr2[i]=k;
     }
     int Max=0;
     for(int i=0;i<v.size();i++)
     {
          int first = (arr1[i]==-1)?i+1:i-arr1[i];
          int second = (arr2[i]==-1)?v.size()-1-i:arr2[i]-i-1;

          int dist = first+second;
          if(dist==0) dist=1;

          Max = max(Max,dist*v[i]);
     }
     return Max;
}
int LargestSubMatrixArea(vector<vector<int>>& v)
{
      vector<int> histogram(v[0].size(),0);
      int res = 0;
      for(int i=0;i<v.size();i++)
      {
          for(int j=0;j<v[i].size();j++)
          {
               if(v[i][j]==0) histogram[j]=0;
               else histogram[j]+=1;
          }
          res = max(res,LargestArea(histogram));
      }
      return res;
}
int main(){
      vector<vector<int>> v{
        {1,0,0,1,1},
        {0,0,0,1,1},
        {1,1,1,1,1},
        {0,1,1,1,1}
      };
      cout<<LargestSubMatrixArea(v)<<'\n';
      return 0;
}