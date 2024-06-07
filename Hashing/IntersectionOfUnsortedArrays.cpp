#include <bits/stdc++.h>
using namespace std;

void PrintIntersection(vector<int>& a,vector<int>& b)
{
     unordered_map<int,int> m;
     for(int i=0;i<b.size();i++) m[b[i]]++;

     for(int i=0;i<a.size();i++)
     {
            if(m.find(a[i]) != m.end() && m[a[i]]!=-1)
            {
                  cout<<a[i]<<" ";
                  m[a[i]]=-1;
            }
     }
     cout<<'\n';
     return;
}
int main()
{
     vector<int> a{10,20,30,10};
     vector<int> b{30,20,10};
     PrintIntersection(a,b);
     return 0;
}