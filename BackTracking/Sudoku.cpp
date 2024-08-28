#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v = {{5,3,0,0,7,0,0,0,0},
{6,0,0,1,9,5,0,0,0},
{0,9,8,0,0,0,0,6,0},
{8,0,0,0,6,0,0,0,3},
{4,0,0,8,0,3,0,0,1},
{7,0,0,0,2,0,0,0,6},
{0,6,0,0,0,0,2,8,0},
{0,0,0,4,1,9,0,0,5},
{0,0,0,0,8,0,0,7,9}};
bool isSafe(int row,int col,int k)
{
     for(int i=0;i<v.size();i++)
     {
         if((v[i][col]==k) || (v[row][i]==k)) return false;
     }
     int s = sqrt(v.size());
     int rs = row-(row%s);
     int cs = col-(col%s);
     for(int i=0;i<s;i++)
     {
        for(int j=0;j<s;j++)
        { 
              if(v[i+rs][j+cs]==k) return false;
        }
     }
     return true;
}
bool Solve()
{
     int i=0,j=0,flag=0;
     for(;i<v.size();i++)
     {
        j=0;
        for(;j<v.size();j++)
        {
             if(v[i][j]==0)
             {
                flag=1;
                break;
             }
        }
        if(flag) break;
     }
    if(i==v.size() && j==v.size()) return true;
    for(int k=1;k<=v.size();k++)
    {
         if(isSafe(i,j,k))
         {
             v[i][j]=k;
             if(Solve()) return true;
         }else v[i][j]=0;
    }
    return false;
}
void Display(){
    for(int i=0;i<v.size();i++)
    {
         for(int j=0;j<v.size();j++) cout<<v[i][j]<<' ';
         cout<<'\n';
    }
}
int main(){
    if(Solve()) Display();
    else cout<<"Solution Doesn't Exist\n";
    return 0;
}