#include <iostream>
using namespace std;
int maxCuts(int n,int a,int b,int c)
{
      if(n<0) return -1;
      if(n==0) return 0;
      int first = maxCuts(n-a,a,b,c);
      int second = maxCuts(n-b,a,b,c);
      int third =  maxCuts(n-c,a,b,c);

      int max = (first>second && first>third)?first:((second>third)?second:third);

      if(max == -1) return -1;
      else 
       return max+1;
}
int main()
{
     int n=9,a=2,b=2,c=2;
     cout<<maxCuts(n,a,b,c)<<'\n';
}