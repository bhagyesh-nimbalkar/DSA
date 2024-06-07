#include <iostream>
using namespace std;

void PrintMergeArray(int* a,int n1,int* b,int n2)
{
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
                if(a[i]<b[j])
                {
                      cout<<a[i]<<' ';
                      i++;
                }
                else 
                {
                     cout<<b[j]<<' ';
                     j++;
                }
        }
        while(i<n1)
        {
                cout<<a[i]<<" ";
                i++;
        }
        while(j<n2)
        {
                cout<<b[j]<<' ';
                j++;
        }
        cout<<'\n';
}
int main()
{
     int arr1[]{10,20,35};
     int arr2[]{5,50,50};
     int size1 = sizeof(arr1)/sizeof(arr1[0]);
     int size2 = sizeof(arr2)/sizeof(arr2[0]);
     PrintMergeArray(arr1,size1,arr2,size2);
     return 0;
}