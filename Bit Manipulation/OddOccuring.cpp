#include <iostream>
using namespace std;

int oddOccuring(int* arr,int n)
{
      int xo=0;
      int xo2=0;
      for(int i=0;i<n;i++)
      {
          if(arr[i]&1)
              xo^=arr[i];
          else 
              xo2^=arr[i];
      }
      cout<<xo<<" "<<xo2<<'\n';
      return 0;
}
int main()
{
     int arr[]{2,3,3,4,4,4,4,8};
     int size = sizeof(arr)/sizeof(arr[0]);

     oddOccuring(arr,size);
     return 0;
}