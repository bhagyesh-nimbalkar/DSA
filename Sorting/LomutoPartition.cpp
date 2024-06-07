#include <iostream>
using namespace std;

void Partition(int* arr,int n,int p)
{
      int i=-1,j=p;
      int pivot = arr[p];
      for(int k=0;k<=j-1;k++)
      {
           if(arr[k]<pivot)
           {
               i++;
               swap(arr[i],arr[k]);
           }
      }
      swap(arr[i+1],arr[j]);
      return;
}
int main()
{
    int arr[]{70,60,80,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int p = 4;
    Partition(arr,n,p);
    for(int i=0;i<n;i++)
    {
           cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return 0;
}