#include <iostream>
#include <math.h>
using namespace std;

bool isPowerofTwo(int a)
{
     if(a==0) return false;
     return ((a&(a-1))==0);
}
int main(void)
{
     cout<<isPowerofTwo(40)<<'\n';
     return 0;
}