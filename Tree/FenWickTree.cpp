#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> bit;

int query(int id)
{ 
     int ans= 0;
     while(id>0)
     {
         ans+=bit[id];
         id -= (id & -id);
     }
     return ans;
}
void update(int id,int val)
{
     while(id<=n)
     {
         bit[id]+=val;
         id+= (id & -id);
     } 
}
int main(){
     cout<<"Enter Array Length:";
     cin>>n;
     bit.resize(n+1,0);
     vector<int> a(n+1,0);
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         update(i,a[i]);
     }
     for(int i=0;i<bit.size();i++) cout<<bit[i]<<' ';
     cout<<'\n';
     int q;
     cout<<"Enter query Length: ";
     int L,R;
     cin>>L>>R;
     int res = query(R) - query(L-1);
     cout<<res<<'\n';
     return 0;
}