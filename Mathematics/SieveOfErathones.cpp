// This is a standard sieve of erathonenes.
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int num;
     cin>>num;
     vector<bool> arr(num+1,true);
     arr[0]=arr[1]=false;

     for(int i=2;i*i<=num;i++)
     {
          for(int j=i*i;j<=num;j+=i)
          {
                arr[j]=false;
          }
     }
     int cnt=0;
     for(int i=0;i<num;i++)
     {
          if(arr[i])
          {
            cout<<i<<' ';
            cnt++;
          }
     }
     cout<<"\n"<<cnt<<"\n";
     return 0;
}