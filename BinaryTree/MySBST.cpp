#include <bits/stdc++.h>
using namespace std;

struct Node{
     int val;
     Node* left,*right;
     Node(int x)
     {
         val=x;
         left=right=nullptr;
     }
};
class Solution
{
    private:
        set<int> st;
    public:
     void Insert(int x)
     {
          st.insert(x);
     }
     bool Search(int x)
     {
          if(st.find(x)==st.end()) return false;
          return true;
     }
     void Delete(int x)
     {
          st.erase(x);
     }
     int kthSmallest(int k)
     {
          int j=1;
          for(auto i=st.begin();i!=st.end();i++,j++)
          {
               if(j==k) return *i;
          }
          return -1;
     }
};
int main()
{
    Solution s;
    s.Insert(10);
    s.Insert(5);
    s.Insert(15);
    s.Insert(20);
    s.Insert(2);

    cout<<s.kthSmallest(3)<<'\n';
    return 0;
}