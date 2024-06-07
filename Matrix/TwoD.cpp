#include <iostream>
using namespace std;

void Print2Darray(int **arr,int m,int n)
{
       for(int i{0};i<m;i++)
       {
            for(int j{0};j<n;j++)   cout<<arr[i][j]<<" ";
            cout<<'\n';
       }
       return;
}
int main()
{
     int **arr;
     int m = 3,n=3;
     int arr2[][n]={
         {1,2,7},
         {3,4,8},
         {5,6,9}
     };
     arr = new int*[m];
     for(int i=0;i<m;i++)
     {
          arr[i] = new int[n];
     }
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               arr[i][j] = arr2[i][j];
          }
     }
     Print2Darray(arr,m,n);
     return 0;
}