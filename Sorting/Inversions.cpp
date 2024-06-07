#include <iostream>
using namespace std;

int Merge(int* arr,int l,int m,int r)
{
       int n1=m+1-l,n2=r-m;
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
       int k=l,res=0;
       i=0,j=0;
       while((i<n1) && (j<n2))
       {
             if(left[i]<=right[j])
             {
                   arr[k]=left[i];
                   i++;
             }
             else 
             {
                  arr[k]=right[j];
                  j++;
                  res+=(n1-i);
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
       return res;
}
int MergeSort(int* arr,int l,int r)
{
        int res=0;
        if(r>l)
        {
            int m = l+(r-l)/2;
            res+=MergeSort(arr,l,m);
            res+=MergeSort(arr,m+1,r);
            res+=Merge(arr,l,m,r);
        }
        return res;
}
int Inversions(int* arr,int n)
{
    return MergeSort(arr,0,n-1);
}
int main()
{
    int a[]{4,2,7,5,2,10};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<Inversions(a,n)<<'\n';
    return 0;
}