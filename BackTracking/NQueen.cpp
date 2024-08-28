#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
bool isSafe(int row,int col,int n)
{
     for(int i=0;i<col;i++)
     {
         if(v[row][i]) return false;
     }
     for(int i=0;i<row;i++){
        if(v[i][col]) return false;
     }
     for(int i=row,j=col;i>=0 && j>=0;i--,j--)
     {
        if(v[i][j]) return false;
     }
     for(int i=row,j=col;i>=0 && j<n;i--,j++)
     {
        if(v[i][j]) return false;
     }
     return true;
}
bool SolveQueen(int row,int col,int n)
{
     if(row==n) return true;
     for(int i=col;i<n;i++)
     {
         if(isSafe(row,i,n))
         {
             v[row][i]=1;
             if(SolveQueen(row+1,0,n)) return true;
             v[row][i]=0;
         }
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
void Reset(){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++) v[i][j]=0;
    }
}
void Solve(int n)
{
  for(int i=0;i<n;i++)
  {
    if(SolveQueen(0,i,n))
    {
       Display();
       Reset();
       cout<<"\n\n";
    }
    else cout<<"NO\n";
  }
}
int main(){
    int N;
    cout<<"Enter a Number:";
    cin>>N;
    v.resize(N,vector<int>(N,0));
    Solve(N);
    return 0;
}