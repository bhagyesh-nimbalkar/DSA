#include <iostream>
using namespace std;
int majority(int* arr,int n)
{
      int res=0,cnt=1;
      for(int i=1;i<n;i++)
      {
         if(arr[res]==arr[i])
             cnt++;
         else 
            cnt--;

         if(cnt==0){
              res=i;
              cnt=1;
         }
      }
      cnt=0;
      for(int i=0;i<n;i++)
      {
         if(arr[res]==arr[i])
            cnt++;
      }
      if(cnt<=n/2)
        res=-1;

      return arr[res];
}
int main()
{
     int arr[]{8,7,6,8,6,6,6,6};
     int size = sizeof(arr)/sizeof(arr[0]);
     cout<<majority(arr,size)<<'\n';
     return 0;
}