#include <bits/stdc++.h>
using namespace std;

int main()
{
     int a = 255;
     int cnt=0;
     while(a)
     {
          a=a&(a-1);
          cnt++;
     }
     cout<<cnt<<'\n';
     return 0;
}