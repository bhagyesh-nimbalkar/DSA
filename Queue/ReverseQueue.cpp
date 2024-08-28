#include <bits/stdc++.h>
using namespace std;

void Reverse(int* arr,int end)
{
      int i=0,j=end;
      while(i<j)
      {
         swap(arr[i],arr[j]);  
         i++;
         j--;
      }
      return;
}
int main(){
     int arr[]{10,20,30,40,50};
     int len = sizeof(arr)/sizeof(arr[0]);
     int rear=len-1;
     Reverse(arr,rear);
     for(int i=0;i<len;i++) cout<<arr[i]<<' ';
     cout<<'\n';
     return 0;
}