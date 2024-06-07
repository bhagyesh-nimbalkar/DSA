#include <bits/stdc++.h>
using namespace std;
void reverse(string& x,int l,int h)
{
       int i=l,j=h;
       while(i<j)
       {
             swap(x[i],x[j]);
             i++;
             j--;
       }
       return;
}
string ReverseWords(string& x)
{
      int prev=0;
      for(int i=0;i<x.size();i++)
      {
          if(x[i]==' ')
          {
             reverse(x,prev,i-1);
             prev=i+1;
          }
      }
      reverse(x,prev,x.size()-1);
      reverse(x,0,x.size()-1);
      return x;
}
int main()
{
     string str="Geeks for geeks";
     cout<<ReverseWords(str)<<'\n';
     return 0;
}