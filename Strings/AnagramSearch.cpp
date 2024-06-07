#include <bits/stdc++.h>
using namespace std;
bool areSame(int* a,int* b,int n)
{
       for(int i=0;i<n;i++)
       {
            if(a[i]!=b[i]) return false;
       }
       return true;
}
bool isPresent(string a,string b)
{
       int m1[256]={0},m2[256]={0};
       for(int i=0;i<b.size();i++)
       {
            m1[a[i]]++;
            m2[b[i]]++;
       }
       for(int i=b.size();i<a.size();i++)
       {
             if(areSame(m1,m2,256)) return true;

             m1[a[i]]++;
             m1[a[i-b.size()]]--;
       }
       return false;
}
int main()
{
       string txt="geeksforgeeks";
       string pat="rseek";
       cout<<boolalpha<<isPresent(txt,pat)<<'\n';
       return 0;
}