#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(vector<int>& v)
{
       int res=0,countOne=0,pre_Sum=0;
       unordered_map<int,int> m;
       for(int i=0;i<v.size();i++)
       {
           pre_Sum+=v[i];
           if(m.find(pre_Sum)!=m.end())
           {
                 res = max(res,i-m[pre_Sum]);
           }   
           if(pre_Sum==0)
           {
                res= max(res,i+1);
           }
           if(m.find(pre_Sum)!=m.end()) continue;
           m[pre_Sum]=i;
       }
       return res;
}
int main()
{
     vector<int> first{0,1,0,0,0,0};
     vector<int> second{1,0,1,0,0,1};
     vector<int> temp(first.size(),0);
     for(int i=0;i<first.size();i++)
     {
            temp[i]=first[i]-second[i];
     }
     cout<<LongestSubarray(temp)<<'\n';
}