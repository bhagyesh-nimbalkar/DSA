#include <bits/stdc++.h>
using namespace std;
bool isRotation(string s1,string s2)
{
      if(s1.size()!=s2.size()) return false;
      if(s1==s2) return true;
      for(int i=0;i<s2.size();i++)
      {
           if(s1[i]==s2[0])
           {
               int end = i,k=1;
               int j=++i;
               while(j!=end && s1[j]==s2[k])
               { 
                     j=(j+1)%s1.size();
                     k++;
               }
               if(j==end) return true;
           }
      }
      return false;
}
int main()
{
     string s1="ABAB";
     string s2="ABBA";
     bool res = isRotation(s1,s2);
     cout<<boolalpha<<res<<'\n';
     return 0;
}