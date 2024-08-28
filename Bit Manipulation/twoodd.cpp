#include <bits/stdc++.h>
using namespace std;

pair<int,int> twoOdd(int* arr,int n)
{
      int xo = 0;
      for(int i{0};i<n;i++)
      {
           xo^=arr[i];
      }
      int num = xo & ~(xo-1);
      int first=0,second=0;
      for(int i{0};i<n;i++)
      {
            if(arr[i]&num)
              first^=arr[i];
            else 
              second^=arr[i];
      }
      return make_pair(first,second);
}
int main()
{
      int arr[]{1,4,4,3};
      int size = sizeof(arr)/sizeof(arr[0]);

      pair<int,int> ans = twoOdd(arr,size);

      cout<<"Ans: "<<ans.first<<" "<<ans.second<<'\n';
      return 0;
}