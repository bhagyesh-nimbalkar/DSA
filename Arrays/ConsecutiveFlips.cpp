#include <iostream>
using namespace std;

void MaxFlips(int* arr,int n)
{
     int find=0;
     if(n<=0) return;
     if(arr[0]==1) find=0;
     else find=1;
     for(int i=0;i<n;i++)
     {
          if(arr[i]==find)
          {
              cout<<"From "<<i;
              while(i<n && arr[i]==find)
              {
                  i++;
              }
              cout<<" to "<<i-1<<'\n';

              i--;
          }
          
     }
}
int main()
{
     int arr[]{1,1,0,0,0,0,1,1,1,1,0};
     int n = sizeof(arr)/sizeof(arr[0]);
     MaxFlips(arr,n);
     return 0;
}