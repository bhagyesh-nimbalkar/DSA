/* This code is useful for the prime divisors of any number. */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
     if(n==0 || n==1) return false;
     if(n==2 || n==3) return true;
     if(n%2==0 || n%3==0) return false;
     for(int i=5;i*i<=n;i+=6)
     {
         if(n%i==0 || n%(i+2)==0) return false;
     }
     return true;
}
vector<int> primeDivisors(int n)
{
     vector<int> ans;
     for(int i=2;i*i<=n;++i)
     {
            while(n%i==0)
              {
                   ans.emplace_back(i);
                   n/=i;
              }
     }
     if(n>1) ans.emplace_back(n);
    // sort(ans.begin(),ans.end());

     return ans;
}
int main()
{
     int num;
     cin>>num;
     vector<int> ans = primeDivisors(num);
     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

     cout<<'\n';
     return 0;
}