#include <iostream>
using namespace std;

void SegregatePositiveNegtive(int* arr,int n)
{
      int i=-1,j=n-1;
      while(i<j)
      {
            while(i<j && arr[j]<0)
            {
                i++;
                swap(arr[i],arr[j]);
            }
           j--;
      }
}
void SegregateEvenOdd(int* arr,int n)
{
      int i=-1,j=n-1;
      while(i<j)
      {
            while((i<j) && (arr[j]%2==0))
            {
                i++;
                swap(arr[i],arr[j]);
            }
           j--;
      }
}
void SegregateBinary(int* arr,int n)
{
      int i=-1,j=n-1;
      while(i<j)
      {
            while(i<j && arr[j]==0)
            {
                i++;
                swap(arr[i],arr[j]);
            }
           j--;
      }
}
int main()
{
     int arr1[]{13,-12,18,-10};
     int n1 = sizeof(arr1)/sizeof(arr1[0]);
     int arr2[]{15,14,13,12};
     int n2 = sizeof(arr2)/sizeof(arr2[0]);
     int arr3[]{0,1,1,1,0};
     int n3 = sizeof(arr3)/sizeof(arr3[0]);

     SegregatePositiveNegtive(arr1,n1);
     for(int i=0;i<n1;i++) cout<<arr1[i]<<' ';
     cout<<'\n';
     SegregateEvenOdd(arr2,n2);
     for(int i=0;i<n2;i++) cout<<arr2[i]<<' ';
     cout<<'\n';
     SegregateBinary(arr3,n3);
     for(int i=0;i<n3;i++) cout<<arr3[i]<<' ';
     cout<<'\n';
     return 0;
}