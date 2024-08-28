#include <iostream>
using namespace std;
int findPeak(int* arr,int n)
{
     if(n==1) return arr[0];
     int low=0,high=n;
     while(low<high)
     {
          int mid = (low+high)/2;
          if((mid==0 || (arr[mid-1]<=arr[mid])) && (mid==n-1 || (arr[mid+1]<=arr[mid]))) return arr[mid];

          if(arr[mid-1]>=arr[mid]) high=mid;
          else low=mid+1;
     }
     return arr[low];
}
int main()
{
     int arr[]{1,2,7,5,10};
     int size = sizeof(arr)/sizeof(arr[0]);
     cout<<findPeak(arr,size)<<'\n';
     return 0;
}