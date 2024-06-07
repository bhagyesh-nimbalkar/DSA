#include <bits/stdc++.h>
using namespace std;


const static int _ = ([](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
})();

void BoundaryTraversal(vector<vector<int>>& v)
{
      if(v.size()==0) {cout<<'\n'; return;}
      for(int j=0;j<v[0].size();j++)  cout<<v[0][j]<<" ";

      for(int i=1,j=v[0].size()-1;i<v.size();i++)   cout<<v[i][j]<<" ";

      if(v.size()<=1) {cout<<'\n'; return;}
      for(int j=v[0].size()-2,i=v.size()-1;j>=0;j--)  cout<<v[i][j]<<" ";

      if(v[0].size()<=1) {cout<<'\n'; return;}
      for(int i=v.size()-2,j=0;i>=1;i--)  cout<<v[i][j]<<" ";

      cout<<'\n';
      return;
}
int main()
{
    vector<vector<int>> arr{
        {1},
        {2},
        {3},
        {4}
     };
     BoundaryTraversal(arr);
     return 0;
}