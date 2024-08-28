#include <bits/stdc++.h>
using namespace std;
int getMax(int a,int b)
{
     return (a>b)?a:b;
}
int sumOfArray(int* arr,int n)
{
      int max=INT_MIN;
      int maxEnd=0;
      for(int i=0;i<n;i++)
      {
           maxEnd = getMax(maxEnd+arr[i],arr[i]);
           max=getMax(maxEnd,max);
      }
      return max;
}
int main()
{
       int arr[]{-5,1,-2,3,-1,2,-2};
       int size = sizeof(arr)/sizeof(arr[0]);
       cout<<sumOfArray(arr,size)<<'\n';
       return 0;
}