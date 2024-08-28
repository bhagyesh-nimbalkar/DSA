#include <iostream>
using namespace std;
// Bubble sort to sort the integers.
void bubbleSort(int* arr,int n)
{
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<n;j++)
            {
                     if(arr[i]<arr[j])
                     {
                          arr[i]^=arr[j];
                          arr[j]^=arr[i];
                          arr[i]^=arr[j];
                     }
            }
       }
       return;
}
int main(){
     int arr[]{5,4,3,2,1};
     int size = sizeof(arr)/sizeof(arr[0]);
     bubbleSort(arr,size);
     for(int i=0;i<size;i++)
     {
            cout<<arr[i]<<" ";
     }
     cout<<'\n';
     return 0;
}