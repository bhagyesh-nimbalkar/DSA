#include <iostream>
using namespace std;


bool FindSum(int* arr,int n,int x)
{
     if(x==0) return false;
     int sum=0,start=0;
     for(int i=0;i<n;i++)
     {
         if(sum<x)
         {
             sum+=arr[i];
         }
         else 
         {
             if(sum==x) return true;
             else 
             {
                  while(start<=i && sum>x)
                  {
                     sum-=arr[start];
                     start++;
                  }

             }
         }
     }
     if(sum==x) return true;

     return false;
}

int main()
{
     int arr[]{1,4};
     int n = sizeof(arr)/sizeof(arr[0]);
     int x = 0;
     if(FindSum(arr,n,x))
       cout<<"Yes\n";
     else 
       cout<<"No\n";
     return 0;
}