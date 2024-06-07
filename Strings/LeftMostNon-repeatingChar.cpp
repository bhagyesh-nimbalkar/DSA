#include <bits/stdc++.h>
using namespace std;

int LeftMostNon_repeating(string x)
{
      int visited[256];
      fill(visited,visited+256,-1);
      for(int i=0;i<x.size();i++)
      {
           if(visited[x[i]]==-1)
           {
                  visited[x[i]]=i;
           }
           else 
           {
                visited[x[i]]=-2;
           }
      }
      int res=INT_MAX;
      for(int i=0;i<256;i++)
      {
          if(visited[i]>=0) {
              res=min(res,visited[i]);
          }
      }
      return (res==INT_MAX)?-1:res;
}
int main()
{
    string str="abcabc";
    cout<<LeftMostNon_repeating(str)<<'\n';
    return 0;
}