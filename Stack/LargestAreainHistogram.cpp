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
int main()
{
     vector<int> v{10,5,6,2};
     cout<<LargestArea(v)<<'\n';
     return 0;
}