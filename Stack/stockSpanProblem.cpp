#include <bits/stdc++.h>
using namespace std;
void PrintStocks(vector<int>& v)
{
     vector<int> indi(v.size(),0);
     indi[0]=-1;
     cout<<1<<" ";
     for(int i=1;i<v.size();i++)
     {
          if(v[i]<v[i-1])
          {
               cout<<1<<" ";
               indi[i]=i-1;
          }
          else{
                int k = indi[i-1];
                while(k!=-1 && v[k]<=v[i])
                {
                      k=indi[k];
                }
                if(k==-1) cout<<i+1<<" ";
                else cout<<i-k<<' ';
          }
     }
     cout<<'\n';
}
int main(){
    vector<int> v{60,10,20,40,55,30,50,70,65};
    PrintStocks(v);
    return 0;
}