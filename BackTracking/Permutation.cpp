#include <bits/stdc++.h>
using namespace std;

void permute(string str,int l,int r)
{
     if(l==r)
     {
        cout<<str<<'\n';
        return;
     }
     for(int i=l;i<r;i++)
     {
         swap(str[i],str[l]);
         permute(str,l+1,r);
         swap(str[i],str[l]);
     }
}
int main()
{
    string str="ABCD";
    permute(str,0,str.size());
    return 0;
}