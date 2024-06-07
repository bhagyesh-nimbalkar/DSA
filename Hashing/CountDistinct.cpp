#include <bits/stdc++.h>
using namespace std;

int CountDistinct(vector<int>& v)
{
      unordered_set<int> s(v.begin(),v.end());
      return s.size();
}
int main()
{
     vector<int> v{10,10,10,1000};
     cout<<"Distinct Elements Count: "<<CountDistinct(v)<<'\n';
     return 0;
}