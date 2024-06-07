#include <iostream>
using namespace std;

int setBits(int* arr,int n)
{
      int num = 255;
      int cnt = 0;
      while(n)
      {
           int k = n&num;
           cnt+=arr[k];
           n = n>>8;
      }
      return cnt;
}
int main()
{
     int tbl[256]{};

     for(int i=1;i<=255;i++)
     {
          tbl[i] = tbl[i&(i-1)] +1;
     }
     cout<<setBits(tbl,40)<<'\n';
}