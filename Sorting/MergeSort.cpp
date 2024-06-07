#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
void Merge(int* arr,int l,int m,int h)
{
       int n1=(m+1)-l,n2=h-m;
       int left[n1],right[n2];
       int i=0,j=0;
       while(i<n1)
       {
             left[i]=arr[l+i];
             i++;
       }
       while(j<n2)
       {
             right[j]=arr[m+1+j];
             j++;
       }
       int k=l;
       i=0;
       j=0;
       while((i<n1) && (j<n2))
       {
             if(left[i]<right[j])
             {
                   arr[k]=left[i];
                   i++;
             }
             else 
             {
                  arr[k]=right[j];
                  j++;
             }
             k++;
       }
       while(i<n1)
       {
              arr[k]=left[i];
              i++;
              k++;
       }
       while(j<n2)
       {
             arr[k]=right[j];
             j++;
             k++;
       }
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
int main()
{
    int arr[]{5,4,3,2,1};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,n-1);
   /* for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    */
    for(auto& [d,v]:mp)
    {
       cout<<d<<' '<<v<<'\n';
    }
    return 0;
}