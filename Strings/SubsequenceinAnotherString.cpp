#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(string a,string b)
{
      if(b=="") return true;
      if(b.size()>a.size()) return false;

      int i=0,j=0;
      while(i<a.size())
      {
            if(a[i]==b[j])
            {
                  i++;
                  j++;
            }
            else  i++;
      }
      return j==b.size();
}
bool isSubSequenceRecursive(string a,string b,int i,int j)
{
       if(b=="") return true;
       if(a==b) return true;
       if(j==b.size()) return true;
       if(i==a.size()) return false;

       if(a[i]==b[j]) 
         return isSubSequenceRecursive(a,b,i+1,j+1);
       else 
         return isSubSequenceRecursive(a,b,i+1,j);
}
int main()
{
     string a="ABCDEAED";
     string b="AED";
     cout<<boolalpha<<isSubSequence(a,b)<<'\n';
     cout<<boolalpha<<isSubSequenceRecursive(a,b,0,0)<<'\n';
     return 0;
}