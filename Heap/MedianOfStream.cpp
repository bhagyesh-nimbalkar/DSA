#include <bits/stdc++.h>
using namespace std;
     vector<float> MedianStream(vector<int>& arr)
     {
          vector<float> ans;
          priority_queue<int> s;
          priority_queue<int,vector<int>,greater<int>> g;
          s.push(arr[0]);
          ans.emplace_back(arr[0]);
          for(int i=1;i<arr.size();i++)
          {
              if(s.size()>g.size())
              {
                   if(s.top()>arr[i]){
                        int x = s.top();
                        s.pop();
                        g.push(x);
                        s.push(arr[i]);
                   }else  g.push(arr[i]);

                   ans.emplace_back((float)(s.top()+g.top())/2);
              }
              else {
                   if(s.top()>arr[i])
                   {
                        g.push(arr[i]);
                        int x = g.top();
                        g.pop();
                        s.push(x);
                   }
                   ans.emplace_back(s.top());
              }
          }
          return ans;
     }
int main(){
     vector<int> v{12,15,10,5,8,7,16};
     vector<float> res = MedianStream(v);
     for(int i=0;i<res.size();i++) cout<<res[i]<<' ';
     cout<<'\n';
     return 0;
}