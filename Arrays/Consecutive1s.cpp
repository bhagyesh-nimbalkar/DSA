#include <iostream>
using namespace std;

int MaxCons(int* arr,int n)
{
      int max=0,cnt=0;
      for(int i{0};i<n;i++)
      {
          if(arr[i]==1)
          {
             cnt++;
          }
          else 
          {
              if(cnt>max)
              {
                max=cnt;
                cnt=0;
              }
          }
      }
      if(cnt>max) 
      { 
              max=cnt;
              cnt=0;
      }
      
      return max;
}
int main()
{
     int arr[]{0,1,1,1,1,0,1,1,1};
     int size=sizeof(arr)/sizeof(arr[0]);
     cout<<MaxCons(arr,size)<<'\n';
     return 0;
}