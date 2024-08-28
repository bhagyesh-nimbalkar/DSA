#include <iostream>
using namespace std;
int maxProfit(int* arr,int n)
{
     int buy=arr[0],sell=arr[0];
     int profit=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>sell)
         {
             sell=arr[i];
         }
         else 
         {
              profit += sell-buy;
              buy=arr[i];
              sell=arr[i];
         }
    }
    profit+=sell-buy;

    return profit;

}
int main()
{
     int arr[]{10,20,30,40};
     int size = sizeof(arr)/sizeof(arr[0]);
     cout<<maxProfit(arr,size)<<'\n';
     return 0;
}