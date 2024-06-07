#include <iostream>
using namespace std;
void SegregateZeroOne(int* arr,int n)
{
       int l=0,mid=0,h=n-1;
       while(mid<h)
       {
            if(arr[mid]==0)
            {
                   swap(arr[l],arr[mid]);
                   l++;
                   mid++;
            }
            else if(arr[mid]==1) mid++;
            else 
            {
                  swap(arr[mid],arr[h]);
                  h--;
            }
       }
}
void SegregatePivot(int* arr,int n)
{
        int i=-1,j=n-1;
        int pivot = arr[0];
        while(i<j)
        {
             while(i<j && arr[j]<=pivot)
             {
                   i++;
                   swap(arr[i],arr[j]);
             }
             j--;
        }
        i=-1;
        while(i<j)
        {
             while(i<j && arr[j]<pivot)
             {
                   i++;
                   swap(arr[i],arr[j]);
             }
             j--;
        }
}
void SegregateRange(int* arr,int n,int l,int h)
{
        int i=-1,j=n-1;
        while(i<j)
        {
             while(i<j && arr[j]<=h)
             {
                   i++;
                   swap(arr[i],arr[j]);
             }
             j--;
        }
        i=-1;
        while(i<j)
        {
             while(i<j && arr[j]<l)
             {
                   i++;
                   swap(arr[i],arr[j]);
             }
             j--;
        }
}
int main()
{
     int arr1[]{2,0,1,0,2,1,2,0,1,2,1,1,1,0,2,2};
     int n1 = sizeof(arr1)/sizeof(arr1[0]);
     SegregateZeroOne(arr1,n1);
     for(int i=0;i<n1;i++) cout<<arr1[i]<<' ';
     cout<<'\n';
     int arr2[]{2,1,2,20,10,20,1};
     int n2 = sizeof(arr2)/sizeof(arr2[0]);
     SegregatePivot(arr2,n2);
     for(int i=0;i<n2;i++) cout<<arr2[i]<<' ';
     cout<<'\n';
     int arr3[]{10,5,6,3,20,9,40};
     int n3 = sizeof(arr3)/sizeof(arr3[0]);
     int l=5,h=10;
     SegregateRange(arr3,n3,l,h);
     for(int i=0;i<n3;i++) cout<<arr3[i]<<' ';
     cout<<'\n';
     return 0;
}