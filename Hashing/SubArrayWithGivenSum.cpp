#include <bits/stdc++.h>
using namespace std;

bool isPresent(vector<int>& v,int X)
{
      unordered_set<int> s;
      int pre_sum=0;
      for(int i=0;i<v.size();i++)
      {
            pre_sum+=v[i];
            if(pre_sum==X) return true;
            if(s.find(pre_sum-X)!=s.end()) return true;
            s.insert(pre_sum);
      }
      return false;
}
int main()
{
     vector<int> v{15,2,8,10,-5,-8,6};
     int sum = 3;
     cout<<boolalpha<<isPresent(v,sum)<<'\n';
     return 0;
}