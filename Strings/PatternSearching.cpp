#include <bits/stdc++.h>
using namespace std;

vector<int> Patterns(string& txt,string& pat)
{ 
       if(pat=="") return {};
       vector<int> res;
       for(int i=0;i<txt.size();i++)
       {
             int j=0,cnt=0,temp=-1,k=i;
             while(j<pat.size() && txt[k]==pat[j]){
                   if(temp==-1) temp=i;
                   cnt++;
                   k++;
                   j++;
             }
             if(cnt==pat.size())  res.emplace_back(temp);
       }
       return res;
}
int main()
{
    string txt = "abcd";
    string pat="xyz";
    vector<int> res = Patterns(txt,pat);
    for(int i=0;i<res.size();i++)
    {
           cout<<res[i]<<" ";
    }
    cout<<'\n';
    return 0;
}