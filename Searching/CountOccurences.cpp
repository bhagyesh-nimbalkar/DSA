#include <bits/stdc++.h>
using namespace std;
pair<int,int> BinSearch(int arr[],int n,int x)
{
        int low=0,high=n,first=-1,second=-1;
        while(low<high)
        {
              int mid = (low+high)/2;
              if(arr[mid]>=x) high=mid;
              else low=mid+1;
        }
        if(arr[low]==x)
        {
             first = low;
        }
        else return {first,second};

        low=0,high=n;
        while(low<high)
        {
              int mid = (low+high)/2;
              if(arr[mid]>x) high=mid;
              else low=mid+1;
        }
        second=low-1;

        return {first,second};
}
int main()
{
     int arr[]{5,10,10,15,15,15,20,20,20,20,20,20};
     int size = sizeof(arr)/sizeof(arr[0]);
     int x=20;
     auto first = lower_bound(arr,arr+size,x);
     auto second = upper_bound(arr,arr+size,x);
     if(first==second) 
       cout<<-1<<" "<<-1<<'\n';
     else 
       cout<<second-first<<'\n';
     pair<int,int> index =  BinSearch(arr,size,x);
     if(index.first!=-1)
       cout<<index.second-(index.first-1)<<'\n';
     else 
       cout<<index.first<<" "<<index.second<<'\n';
     return 0;
}