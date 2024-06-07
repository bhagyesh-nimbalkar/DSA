// This code give power of two numbers in recursive way.
#include <iostream>
using namespace std;

int power(int a,int b)
{
      if(b==0)
        return 1;
      
      int temp = power(a,b/2);
      temp*=temp;
      if(b&1)
        return temp*a;
      else 
        return temp;
}
int main()
{
     int x,n;
     cin>>x>>n;
     cout<<power(x,n)<<'\n';
     return 0;
}