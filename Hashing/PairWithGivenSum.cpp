#include <bits/stdc++.h>
using namespace std;

bool isSumPresent(vector<int>& v,int sum)
{
       unordered_map<int,int> m;
       for(int i=0;i<v.size();i++) m[v[i]]++;

       for(int i=0;i<v.size();i++)
       {
             int x = sum-v[i];
             if(m.find(x)!=m.end())
             {
                   if(x!=v[i]) return true;
                   if(m[x]>1) return true;
             }
       }
       return false;
}


int main()
{
     vector<int> v{5,8,-3,6};
     int sum = 3;
     cout<<boolalpha<<isSumPresent(v,sum)<<'\n';
     return 0;
}