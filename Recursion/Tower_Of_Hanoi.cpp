#include <iostream>
using namespace std;

void TOH(int n,char a,char b,char c)
{
     if(n==1)
     {
         cout<<"Move Disc 1 from "<<a<<" to "<<c<<'\n';
         return;
     }
     TOH(n-1,a,c,b);
     cout<<"Move Disc "<<n<<" from "<<a<<" to "<<c<<'\n';
     TOH(n-1,b,a,c);
}
int main()
{
     TOH(6,'A','B','C');
     return 0;
}