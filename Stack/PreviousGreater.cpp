#include <bits/stdc++.h>
using namespace std;
void previousGreater(vector<int>& v)
{
     vector<int> mapping(v.size(),0);
     mapping[0]=-1;
     cout<<-1<<' ';
     for(int i=1;i<v.size();i++)
     {
           if(v[i-1]>v[i]) 
           {
                cout<<v[i-1]<<' ';
                mapping[i]=i-1;
           }
           else {
                int k = mapping[i-1];
                while(k!=-1 && v[k]<=v[i])
                {
                      k= mapping[k];
                }
                if(k==-1){
                     cout<<-1<<' ';
                     mapping[i]=-1;
                }
                else {
                      cout<<v[k]<<" ";
                      mapping[i]=k;
                }
           }
     }
     cout<<'\n';
}
int main(){
    vector<int> v{12,10,8};
    previousGreater(v);
    return 0;
}