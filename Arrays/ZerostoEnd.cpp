#include <iostream>
using namespace std;
void slide(int* arr,int n)
{
     int k=n;
     for(int i=0;i<n;i++)
     {
         if(arr[i]==0)
         {
             k=i;
             break;
         }
     }
     for(int i = k+1;i<n;i++)
     {
           if(arr[i]!=0)
           { 
               swap(arr[i],arr[k]);
               k++;
               while(k<n && arr[k]!=0)
               {
                  k++;
               }
               i=k+1;
           }
     }
}
int main()
{
    int arr[]{10,8,0,0,12,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    slide(arr,size);
    for(int i=0;i<size;i++)
    {
         cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return 0;
}