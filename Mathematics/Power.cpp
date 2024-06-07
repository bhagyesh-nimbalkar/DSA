/* This code give power of two numbers in iterative way. */
#include <iostream>
using namespace std;

int power(int a,int b)
{
    int res=1;
    while(b)
    {
      if(b&1)
      {
          res*=a;
          b-=1;
      }
      else 
      {
            int part = b/2;
            int mul = 1;
            while(part--)
            {
                 mul*=a;
            }
            mul*=mul;
            res*=mul;
            b=0;
      }
    }
      return res;
}
int main()
{
     int x,n;
     cin>>x>>n;
     cout<<power(x,n)<<'\n';
     return 0;
}