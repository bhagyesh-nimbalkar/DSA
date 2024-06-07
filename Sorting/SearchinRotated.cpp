#include <iostream>
using namespace std;
int BinSearch(int* arr,int n,int x)
{
       int low=0,high=n-1;
       while(low<=high)
       {
          int mid = (low+high)/2;
          if(arr[mid]==x) return mid;
          else if(arr[low]<=x && arr[high]>=x) 
          {
              if(arr[mid]>x) high=mid-1;
              else  low=mid+1;
          }
          else if(arr[low]>x) low=mid+1;
          else 
            high=mid-1;
       }
       return -1;
}
int main()
{
     int arr[]{100,200,300,400,20,30,40};
     int x=50;
     size_t size = sizeof(arr)/sizeof(arr[0]);
     cout<<BinSearch(arr,size,x)<<'\n';
     return 0;
}