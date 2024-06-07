#include <iostream>
using namespace std;

unsigned long long int squareRoot(unsigned long long int x)
{
      
      unsigned long long int low=1,high=(x/2);
      while(low<high)
      {
           unsigned long long int mid = (low+high)/2;
           if(mid*mid >= x)  high=mid;
           else low=mid+1;
      }
      if(low*low == x || low<4) return low;
      else  return low-1; 
}
int main()
{
     cout<<squareRoot(5)<<'\n';
     return 0;
}