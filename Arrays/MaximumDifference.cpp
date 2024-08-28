#include <bits/stdc++.h>
using namespace std;

int maxDiff(int* arr,int n)
{
     int min = INT_MAX;
     int ans = 0;
     for(int i=0;i<n;i++)
     {
          if(arr[i]<min)
          {
             min = arr[i];
          }
          if((arr[i]-min)>ans)
            ans= arr[i]-min;
     }
     return ans;
}
int main()
{
     int arr1[]{2,3,10,6,4,8,1};
     int size1=sizeof(arr1)/sizeof(arr1[0]);

     int arr2[]{7,9,5,6,3,2};
     int size2 = sizeof(arr2)/sizeof(arr2[0]);

     int arr3[]{10,20,30};
     int size3 = sizeof(arr3)/sizeof(arr3[0]);

     int arr4[]{30,10,8,2};
     int size4 = sizeof(arr4)/sizeof(arr4[0]);

     cout<<maxDiff(arr1,size1)<<'\n';
     cout<<maxDiff(arr2,size2)<<'\n';
     cout<<maxDiff(arr3,size3)<<'\n';
     cout<<maxDiff(arr4,size4)<<'\n';

     return 0;
}