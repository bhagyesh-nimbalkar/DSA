#include <bits/stdc++.h>
using namespace std;


void Union(int* a,int* b,int n1,int n2)
{
        int i=0,j=0;
        while((i<n1) && (j<n2))
        {
               if((i>0) && (a[i-1]==a[i]))
               {
                    i++;
               }
               else if((j>0) && (b[j-1]==b[j]))
               {
                    j++;
               }
               else if(a[i]==b[j])
               {
                     cout<<a[i]<<' ';
                     i++;
                     j++;
               }
               else if(a[i]>b[j])
               {
                     cout<<b[j]<<" ";
                     j++;
               }
               else 
               {
                     cout<<a[i]<<" ";
                     i++;
               }
        }
       while(i<n1)
       {
              if(i==0) cout<<a[i]<<' ';
              else if(a[i-1]!=a[i])
              {
                   cout<<a[i]<<' ';
              }
              i++;
       }
       while(j<n2)
       {
              if(j==0) cout<<b[j]<<" ";
              else if(b[j-1]!=b[j])
              {
                    cout<<b[j]<<" ";
              }
              j++;
       }
       cout<<'\n';
       return;
}
int main()
{
     int a[]{2,3,3,3,4,4};
     int b[]{8,10,12,12};
     int n1 = sizeof(a)/sizeof(a[0]);
     int n2 = sizeof(b)/sizeof(b[0]);
     Union(a,b,n1,n2);
     return 0;
}