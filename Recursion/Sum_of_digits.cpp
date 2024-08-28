#include <iostream>
using namespace std;

int sum(int n)
{ 
     return (n==0)?0:(n%10)+sum(n/10);
}
int main()
{
     cout<<sum(1234)<<'\n';
     return 0;
}