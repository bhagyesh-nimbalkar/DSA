#include <iostream>
#include <vector>
using namespace std;

void PrintBackward(vector<vector<int>>& v,int i,int j)
{
       if(i<v.size() && j<v[i].size()) 
       {
            for(int j=v[i].size()-1;j>=0;j--) cout<<v[i][j]<<" ";
       }
}
void PrintForward(vector<vector<int>>& v,int i,int j)
{
       if(i<v.size() && j<v[i].size()) 
       {
            for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
       }
}
void SnakePattern(vector<vector<int>>& v)
{
       int flag=0;
       for(int i=0;i<v.size();i++)
       {
             if(flag)
             {
                  PrintBackward(v,i,v[i].size()-1);
             }
             else 
             {
                   PrintForward(v,i,0);
             }
             flag = ~flag;
       }
       cout<<'\n';
       return;
}
int main()
{
     vector<vector<int>> arr{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
     };
     SnakePattern(arr);
     return 0;
}