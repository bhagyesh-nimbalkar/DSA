#include <iostream>
using namespace std;
int BinSearch(int* arr,int low,int high,int x)
{
       while(low<high)
       {
              int mid = (low+high)/2;
              if(arr[mid]==x) return mid;
              else if(arr[mid]>x) high=mid;
              else 
              low=mid+1;
       }
       return -1;
}
int Find(int* arr,int x)
{
       long long int i=1;
       while(arr[i]<=x)
       {
              if(arr[i]==x) return i;
              if(arr[i]<x)  i*=2;
       }
       return BinSearch(arr,0,i,x);
}
int main()
{
      int arr[]{1,10,200,400,500,1000,2000,3000,4000,5000,6000,7000,8000,10000,11000,12000};
      cout<<Find(arr,2000)<<'\n';
      return 0;
}