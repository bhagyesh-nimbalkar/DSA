#include <bits/stdc++.h>
using namespace std;
    bool isPair(int* arr,int n,int x,int s)
    {
           int i=s,j=n-1;
           while(i<j)
           {
                  int sum = arr[i]+arr[j];
                  if(sum==x) return true;
                  else if(sum>x) j--;
                  else i++;
           }
           return false;
    }
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n-2;i++)
        {
            if(X>A[i])  
            {
                int x = X-A[i];
                if(isPair(A,n,x,i+1)) return true;
            }
        }
        return false;
    }
    int main()
    {
           int arr[]{1,4,45,6,10,8};
           int size = sizeof(arr)/sizeof(arr[0]);
           int x=13;
           if(find3Numbers(arr,size,x)) cout<<1<<'\n';
           else cout<<0<<'\n';
           return 0;
    }