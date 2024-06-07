#include <bits/stdc++.h>
using namespace std;
int FindMax(vector<int>& v)
{
      int Max=0;
      for(int i=0;i<v.size();i++)
      {
           Max=max(Max,v[i]);
      }
      return Max;
}
int LongestSubsequence(vector<int>& v)
{
      /*sort(v.begin(),v.end());
      int cnt=1,res=0;
      for(int i=1;i<v.size();i++)
      {
            if(v[i]-v[i-1]==1)
            {
                  cnt++;
            }
            else if(v[i]==v[i-1]){}             // Sorting Method
            else {
                  cnt=1;
            }
            res = max(res,cnt);
      }
      return res; */
      int Size = FindMax(v);
      vector<int> temp(Size+1,false);
      for(int i=0;i<v.size();i++)
      {
            temp[v[i]]=true;
      }
      int res=0,cnt=0;
      for(int i=0;i<temp.size();i++)
      {
             if(temp[i]) cnt++;
             else cnt=0;

             res=max(res,cnt);
      }
      return res;
}
int main()
{
      vector<int> v{1,3,4,3,3,2,9,10};
      cout<<LongestSubsequence(v)<<'\n';
      return 0;
}