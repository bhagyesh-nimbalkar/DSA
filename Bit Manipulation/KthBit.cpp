#include <iostream>
using namespace std;


int main()
{
     int a = 3;
     int k = 1;
     if((a>>k)&1)
       cout<<"Yes\n";
     else 
       cout<<"No\n";
     return 0;
}