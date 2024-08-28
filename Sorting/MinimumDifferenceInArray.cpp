#include <bits/stdc++.h>
using namespace std;

void Merge(int* arr,int l,int m,int h)
{
    int n1 = (m+1)-l,n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++) {left[i]=arr[l+i];}

    for(int i=0;i<n2;i++) {right[i]=arr[m+1+i];}

    int k=l,i=0,j=0;
    while((i<n1) && (j<n2))
    { 
          if(left[i]<right[j])
          {
              arr[k]=left[i];
              i++;
              k++;
          }
          else{
                arr[k]=right[j];
                j++;
                k++;
          }
    }
    while(i<n1){ arr[k]=left[i]; i++; k++;}
    while(j<n2){ arr[k]=right[j];j++;k++;}
}
void MergeSort(int* arr,int l,int h)
{
        if(h>l)
        {
              int m = l+(h-l)/2;
              MergeSort(arr,l,m);
              MergeSort(arr,m+1,h);
              Merge(arr,l,m,h);    
        }
}
int MinDiff(int* arr,int n)
{
    MergeSort(arr,0,n-1);
    int min = INT_MAX;
    for(int i=1;i<n;i++)
    {
           if(arr[i]-arr[i-1] < min)
           { 
               min = arr[i]-arr[i-1];
           }
    }
    return min;
}
int main()
{
    int arr[]{10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<MinDiff(arr,n)<<'\n';
    return 0;
}