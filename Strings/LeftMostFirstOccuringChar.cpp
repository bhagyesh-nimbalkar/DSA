#include <bits/stdc++.h>
using namespace std;
int LeftMostOccurence(string x)
{
       unordered_map<char,int> mp;
       int res=-1,Min=x.size();
       for(int i=0;i<x.size();i++)
       {  
             if(mp.find(x[i])!=mp.end())
             {
                   Min = min(Min,mp[x[i]]);
                   res=Min;
             }
             else {
                     mp[x[i]]=i;
             }
       }
       return res;
}
int main()
{
     string str="abcccb";
     cout<<LeftMostOccurence(str)<<'\n';
     return 0;
}