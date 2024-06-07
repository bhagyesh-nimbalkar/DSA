#include <iostream>
using namespace std;
int maxAppearing(int* arr,int n)
{
    int max=0;
    int index=0;
    for(int i=1;i<n;i++)
    {
         arr[i]+=arr[i-1];

         if(arr[i]>max) 
         { 
            max=arr[i];
            index=i;
         }
    }
    return index;
}
int main()
{
    int n = 1e5+7;
    int arr[n]{};
    int left[]{1,2};
    int right[]{5,4};
    int size=sizeof(left)/sizeof(left[0]);

    for(int i=0;i<size;i++)
    {
         arr[left[i]]+=1;
         arr[right[i]+1]+=-1;
    }
    cout<<maxAppearing(arr,n)<<'\n';
    return 0;
}