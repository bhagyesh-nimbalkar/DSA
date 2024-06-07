#include <iostream>
using namespace std;
int Repeat(int* arr,int n)
{
       int slow = arr[0],fast=arr[0];
       do{
              slow = arr[slow];
              fast = arr[arr[fast]];
       }while(slow!=fast);                                  /* Find the cycle in array algorithm */
       slow=arr[0];
       while(slow!=fast)
       {
               slow=arr[slow];
               fast=arr[fast];
       }
       return slow;
}
int main()
{
      int arr[]{1,2,3,4,4};
      int size = sizeof(arr)/sizeof(arr[0]);
      cout<<Repeat(arr,size)<<'\n';
      return 0;
}