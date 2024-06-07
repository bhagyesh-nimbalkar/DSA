#include <iostream>
using namespace std;

int partition(int * arr,int l,int h)
{
       int i=l-1,j=h+1;
       int pivot = arr[l];
       while(true)
       {
            do{ 
                  i++;
            }while(arr[i]<pivot);
            do{
                 j--;
            }while(arr[j]>pivot);

            if(i>=j) return j;
            swap(arr[i],arr[j]);
       }
       return -1;
}
void quickSort(int* arr,int l,int h)
{
      if(l<h)
      {
       int p = partition(arr,l,h);
       quickSort(arr,l,p);
       quickSort(arr,p+1,h);
      }
}
int main()
{
     int arr[]{20,4,5,3,6,7,33,80,6,44,12,23,78,44,23,90};
     int n = sizeof(arr)/sizeof(arr[0]);
     quickSort(arr,0,n-1);
     for(int i=0;i<n;i++)
     {
         cout<<arr[i]<<" ";
     }
     cout<<'\n';
     return 0;
}