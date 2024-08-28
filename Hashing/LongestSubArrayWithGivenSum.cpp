#include <bits/stdc++.h>
using namespace std;


int LongestSum(vector<int>& v,int sum)
{
      unordered_map<int,int> m;
      int pre_Sum=0,res=0;
      for(int i=0;i<v.size();i++)
      {
            pre_Sum+=v[i];
            if(m.find(pre_Sum-sum)!=m.end())
            {
                  if(i-m[pre_Sum-sum]>res) res=max(res,i-m[pre_Sum-sum]);
            }
            if(pre_Sum==sum){
                  res = max(res,i+1);
            }
            if(m.find(pre_Sum)!=m.end())
            {
                 continue;
            }
            m[pre_Sum]=i;
      }
      return res;
}
int main()
{
     vector<int> v{5,2,3};
     int sum = 5;
     cout<<LongestSum(v,sum)<<'\n';
     return 0;
}