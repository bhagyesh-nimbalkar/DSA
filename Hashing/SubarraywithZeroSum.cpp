#include <bits/stdc++.h>
using namespace std;

bool IsPresent(vector<int>& v)
{
       unordered_set<int> s;
       int pre_sum=0;
       for(int i=0;i<v.size();i++)
       {
           pre_sum+=v[i];
           if(s.find(pre_sum)!=s.end()) return true;
           if(pre_sum==0) return true;
           s.insert(pre_sum);
       }
       return false;
}
int main()
{
     vector<int> v{-3,2,1};
     cout<<boolalpha<<IsPresent(v)<<'\n';
     return 0;
}