#include <bits/stdc++.h>
using namespace std;

int N=5;
vector<vector<int>> Sol(N,vector<int>(N,0));
bool RatinMaze(vector<vector<int>>& Maze,int i,int j,int n)
{
    if((i==n-1) && (j==n-1)){
        Sol[i][j]=1;
        return true;
    }
    if(i<0 || i>=n || j<0 || j>=n) return false;
    if(Maze[i][j]==0) return false;
    Sol[i][j]=1;
    return (RatinMaze(Maze,i+1,j,n) || RatinMaze(Maze,i,j+1,n));
}
int main()
{
    vector<vector<int>> Maze={
        {1,0,0,0,1},
        {1,1,0,1,0},
        {0,1,0,0,1},
        {1,1,1,1,0},
        {0,0,1,1,1}
    };
    cout<<RatinMaze(Maze,0,0,N)<<"\n\n\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++) cout<<Sol[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}