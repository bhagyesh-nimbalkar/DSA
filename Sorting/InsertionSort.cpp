#include <iostream>
using namespace std;
// Insertion Sort Algorithm to sort the integers.
void insertionSort(int* arr,int n)
{
       for(int i=1;i<n;i++)
       {
               int j=i-1;
               int key = arr[i];
               while((j>=0) && (arr[j]>key))
               {
                     arr[j+1]=arr[j];
                     j--;
               }
               arr[j+1]=key;
       }
}
int main()
{
    int arr[]{8,7,0,6,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);
    for(int i=0;i<size;i++)
    {
           cout<<arr[i]<<" ";
    }
    cout<<'\n';
    return 0;
}