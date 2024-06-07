#include <bits/stdc++.h>
using namespace std;

int Distribution(int* arr,int n,int m)
{
      int pos = m-1;
      sort(arr,arr+n);
      int res = INT_MAX;
      for(int i=pos;i<n;i++)
      {
            res = min(res,arr[i]-arr[i-pos]);
      }
      return res;
}
int main()
{
     int arr[]{3,4,1,9,56,7,9,12};
     int n = sizeof(arr)/sizeof(arr[0]);
     int m = 7;
     cout<<Distribution(arr,n,m)<<'\n';
     return 0;
}