#include <bits/stdc++.h>
using namespace std;

bool checkParen(string& s)
{
      stack<char> st;
      unordered_map<char,char> mp{
        {')','('},{']','['},{'}','{'}
      };
      for(auto x:s)
      {
           if(mp.count(x))
           {
                    if(st.empty()) return false;
                    if(st.top()!=mp[x]) return false;
                    st.pop();
          }
          else st.push(x);
      }
      if(!st.empty()) return false;
      return true;
}
int main()
{
     string str="{}([])";
     cout<<boolalpha<<checkParen(str)<<'\n';
     return 0;
}