#include <bits/stdc++.h>
using namespace std;
int Fact(int x)
{
      int sum=1;
      for(int i=1;i<=x;i++) sum*=i;

      return sum;
}
int Rank(string& x)
{
     const int CHAR =256;
     int res=0;
     int n = x.size();
     int mul = Fact(n);
     int mp[CHAR]={0};
     for(int i=0;i<x.size();i++)
     {
           mp[x[i]]++;
     }
     for(int i=1;i<CHAR;i++)  mp[i]+=mp[i-1];

     for(int i=0;i<n-1;i++)
     {
          mul /= (n-i);

          res+= mul*mp[x[i]-1];

          for(int j=x[i];j<CHAR;j++) mp[j]--;
     }
     return res+1;
}
int main()
{
     string str="CBA";
     cout<<Rank(str)<<'\n';
     return 0;
}