#include <iostream>
using namespace std;
int* Sort(int* arr,int low,int mid,int high)
{
      int* ans = new int[(high+1)-low];
      int i=low,j=mid+1,k=0;
      while(i<=mid && j<=high)
      {
              if(arr[i]<arr[j])
              {
                     ans[k]=arr[i];
                     i++;
              }
              else 
              {
                    ans[k]=arr[j];
                    j++;
              }
              k++;
      }
      while(i<=mid)
      {
             ans[k]=arr[i];
             i++;
             k++;
      }
      while(j<=high)
      { 
           ans[k]=arr[j];
           j++;
           k++;
      }
      return ans;
}
int main()
{
     int arr[]{5,8,12,14,7};
     int n = sizeof(arr)/sizeof(arr[0]);
     int low=0,mid=3,high=4;
     int* res = Sort(arr,low,mid,high);
     for(int i=0;i<(high+1);i++)
     {
             cout<<res[i]<<" ";
     }
     cout<<'\n';
     delete[] res;
     return 0;
}