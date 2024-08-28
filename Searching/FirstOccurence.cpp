#include <iostream>
using namespace std;
int BinSearch(int arr[],int n,int x)
{
        int low=0,high=n;
        while(low<high)
        {
              int mid = (low+high)/2;
              if(arr[mid]>=x) high=mid;
              else low=mid+1;
        }
        return low;
}
int main()
{
     int arr[]{5,10,10,15,15,15};
     int size = sizeof(arr)/sizeof(arr[0]);
     int x=25,index = BinSearch(arr,size,x);
     if(arr[index]==x)
       cout<<index<<'\n';
     else 
       cout<<-1<<'\n';
     return 0;
}