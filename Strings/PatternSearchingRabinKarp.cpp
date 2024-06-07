#include <bits/stdc++.h>
using namespace std;

int hashFun(unordered_map<char,int>& mp,string& pat)
{
         int sum = 0;
         for(int i=0;i<pat.size();i++)
         {
             sum+=mp[pat[i]];
         }
         return sum;
}
bool Equal(string& txt,string& pat,int start)
{ 
       for(int i=0;i<pat.size();i++)
       {
              if(pat[i]!=txt[start]) return false;
              start++;
       }
       return true;
}
vector<int> Patterns(string& txt,string& pat)
{
      if(pat.size()>txt.size()) return {};
      unordered_map<char,int> mp;
      vector<int> res;
      int num = 0;
      for(int i=0;i<txt.size();i++)
      {
             if(mp.find(txt[i])==mp.end())
             {
                   mp[txt[i]]=num;
                   num++;
             }
      }
      int hash2=hashFun(mp,pat);
      int i=0;
      int hash1=0;
      for(;i<pat.size();i++)
      {
            hash1+=mp[txt[i]];
      }
      int prev=0;
      for(int k=pat.size();k<=txt.size();k++)
      {
            cout<<hash1<<" "<<hash2<<'\n';
            if(hash1==hash2 && Equal(txt,pat,prev))
            {
                res.emplace_back(prev);
            }
            hash1-=mp[txt[prev]];
            prev++;
            hash1+=mp[txt[k]];
      }
      return res;
}
int main()
{
     string txt="example@email.com";
     string pat="m";
     vector<int> res = Patterns(txt,pat);
     for(int i=0;i<res.size();i++)
     {
          cout<<res[i]<<" ";
     }
     cout<<'\n';
     return 0;
}