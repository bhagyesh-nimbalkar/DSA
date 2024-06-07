// This code gives the answer for trailing zeros in the factorial of any number. 
#include <iostream>
using namespace std;

int TrailFacZero(int a)
{
       int sum = 0;
       while(a)
       {
            sum+=a/5;
            a/=5;
       }
       return sum;
}
int main()
{
      int num;
      cin>>num;
      cout<<TrailFacZero(num)<<'\n';
      return 0;
}