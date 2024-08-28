/* This code is giving all the divisors of any number. */
#include <bits/stdc++.h>
using namespace std;
void printDivisors(int n)
{
      for(int i=1;i*i<n;++i)
      {
           if(n%i==0) cout<<i<<" ";
      }
      for(int i=sqrt(n);i>=1;i--)
      {
            if(n%i==0) cout<<n/i<<' ';
      }
      cout<<'\n';
}
int main()
{
     int num;
     cin>>num;
     printDivisors(num);
     return 0;
}