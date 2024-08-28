#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(vector<int>& v,int sum)
{ 
       int res=0,countOne=0,pre_Sum=0;
       for(int i=0;i<v.size();i++)
       {
            if(v[i]==0) v[i]=-1;
       }
       unordered_map<int,int> m;
       for(int i=0;i<v.size();i++)
       {
           pre_Sum+=v[i];
           if(m.find(pre_Sum-sum)!=m.end())
           {
                res = max(res,i-m[pre_Sum-sum]);
           }   
           if(pre_Sum==sum)
           {
                res = max(res,i+1);
           }
           if(m.find(pre_Sum)!=m.end()) continue;
           m[pre_Sum]=i;
       }
       return res;
}
int main()
{
     vector<int> v{0,0,1,0,1,1};
     cout<<LongestSubarray(v,0)<<'\n';
     return 0;
}