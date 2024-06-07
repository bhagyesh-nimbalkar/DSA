#include <iostream>
using namespace std;
bool isPair(int* arr,int n,int x)
{
      int i=0,j=n-1;
      while(i<j)
      {
           int sum = arr[i]+arr[j];
           if(sum==x)
             return true;
           else if(sum>x) j--;
           else i++;
      }
      return false;
}
int main()
{
     int arr[]{3,8,13,18};
     int size = sizeof(arr)/sizeof(arr[0]);
     int x = 21;
     if(isPair(arr,size,x))
       cout<<"Found\n";
     else cout<<"Not Found\n";
     return 0;
}