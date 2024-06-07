#include <bits/stdc++.h>
using namespace std;

pair<int,int> BinSearch(vector<vector<int>>& v,int l,int h,int find,int i)
{
       while(l<h)
       {
            int mid = (l+h)/2;
            if(v[i][mid]==find) return{i,mid};
            else if(v[i][mid]>find) h=mid;
            else l=mid+1;
       }
       return {-1,-1};
}

pair<int,int> FindinMatrix(vector<vector<int>>& v,int find)
{
      for(int i=0;i<v.size();i++)
      {
         if((v[i][0]<=find) && (v[i][v[i].size()-1]>=find)) 
         {
            pair<int,int> res = BinSearch(v,0,v[i].size(),find,i);
            if(res.first!=-1) return res;
         }
      }
     return {-1,-1};
}
int main()
{
     vector<vector<int>> arr{
        {10,20},
        {12,30}
     };
     int find = 30;
     pair<int,int> res = FindinMatrix(arr,find);
     if(res.first==-1)  cout<<"Not Found\n";
     else  cout<<"Found at: ("<<res.first<<","<<res.second<<")\n";
     return 0;
     return 0;
}