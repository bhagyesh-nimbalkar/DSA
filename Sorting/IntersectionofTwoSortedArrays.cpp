#include <bits/stdc++.h>
using namespace std;


void Intersection(int* a,int* b,int n1,int n2)
{
        int prev=-1;
        int i=0,j=0;
        while((i<n1) && (j<n2))
        {
               if((a[i]==b[j]))
               {
                  if(a[i]!=prev)
                  {
                    cout<<a[i]<<' ';
                    prev=a[i];
                  }
                  i++;
                  j++;
               }
               else if(a[i]>b[j])
               {
                     j++;
               }
               else 
                     i++;
        }
       cout<<'\n';
       return;
}
int main()
{
     int a[]{2,20,20,40,60};
     int b[]{10,20,20,20};
     int n1 = sizeof(a)/sizeof(a[0]);
     int n2 = sizeof(b)/sizeof(b[0]);
     Intersection(a,b,n1,n2);
     return 0;
}