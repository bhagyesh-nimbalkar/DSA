#include <iostream>
using namespace std;

int getMax(int a,int b)
{
     return (a>b)?a:b;
}
int MaxEO(int* arr,int n)
{
     int max=0,len=0,flag=0;
     if(n==0) return 0;
     if(arr[0]&1)
      flag=0;
     else 
      flag=1;
     
     len=1;
     for(int i=1;i<n;i++)
     {
          if(flag==0 && arr[i]%2==0)
          {
               len++;
               flag  =1;
          }
          else if(flag==1 && arr[i]&1)
          {
               len++;
               flag= 0;
          }
          else 
          {
              len=1;
              if(arr[i]&1) flag=0;
              else flag=1;
          }
          max = getMax(len,max);
     }
     return max;
}
int main()
{
     int arr[]{5,10,20,6,3,8};
     int size = sizeof(arr)/sizeof(arr[0]);
     cout<<MaxEO(arr,size)<<'\n';
     return 0;
}