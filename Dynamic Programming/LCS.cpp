#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int SolveLcs(string& a,string& b,int m,int n)
{
     if(m==0 || n==0) return 0;
     if(v[m-1][n-1]!=0) return v[m-1][n-1];
     if(a[m-1]==b[n-1]){
        return v[m-1][n-1] = 1+SolveLcs(a,b,m-1,n-1);
     }
     return v[m-1][n-1]= max(
        SolveLcs(a,b,m-1,n),
        SolveLcs(a,b,m,n-1)
     );
}
int main()
{
    string s1="ABCDEFGHI";
    string s2="CEGHXTOI";
    v.resize(s1.size(),vector<int>(s2.size(),0));
    cout<<SolveLcs(s1,s2,s1.size(),s2.size())<<'\n';
    for(int i=0;i<v.size();i++)
    {
       for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<' ';
       cout<<'\n';
    }
    return 0;
}