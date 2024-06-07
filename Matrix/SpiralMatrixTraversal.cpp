#include <bits/stdc++.h>
using namespace std;

void PrintSpiral(vector<vector<int>>& v)
{
     if(v.size()==0)return;
     int up=0,down=v.size()-1,left=0,right=v[0].size()-1;
     while((up<down) || (left<right))
     {
          for(int i=left;i<=right;i++) cout<<v[up][i]<<" ";
          if(up>=down) return;
          up++;


          for(int i=up;i<=down;i++)  cout<<v[i][right]<<" ";
          if(left>=right) return;
          right--;

          for(int i=right;i>=left;i--) cout<<v[down][i]<<" ";
          if(up>=down) return;
          down--;

          for(int i=down;i>=up;i--)  cout<<v[i][left]<<" ";
          if(left>=right) return;
          left++;
          
     }
     cout<<'\n';
     return;
}
int main()
{
     vector<vector<int>> mat {{1,2,3,4,5},
     {6,7,8,9,10},
     {11,12,13,14,15},
     {16,17,18,19,20}
            };
     PrintSpiral(mat);
     return 0;
}