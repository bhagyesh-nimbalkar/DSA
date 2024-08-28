#include <bits/stdc++.h>
using namespace std;
void Transpose(vector<vector<int>>& v)
{
     for(int i=0;i<v.size();i++)
     {
            int j=i;
            while(j<v[i].size())
            {
                   swap(v[j][i],v[i][j]);
                   j++;
            }
     }
}
void PrintArray(vector<vector<int>>& v)
{
       for(int i=0;i<v.size();i++)
       {
         for(int j=0;j<v[i].size();j++)
         {
                cout<<v[i][j]<<' ';
         }
         cout<<'\n';
       }
}
int main()
{
     vector<vector<int>> arr{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
     };
     Transpose(arr);
     PrintArray(arr);
     return 0;
}