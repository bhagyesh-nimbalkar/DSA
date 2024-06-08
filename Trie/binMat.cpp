#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isEnd;
    TrieNode* child[2];
    TrieNode(){
        isEnd=false;
        child[0]=child[1]=NULL;
    }
};
class Trie{
    private: 
      TrieNode* root;
    public:
      Trie(){
         root = new TrieNode();
      }
      bool insert(vector<int>& v)
      {
          int flag=false;
          TrieNode* curr = root;
          for(int i=0;i<v.size();i++)
          {
              if(!curr->child[v[i]]) {
                flag=true;
                curr->child[v[i]] = new TrieNode();
              }
              curr=curr->child[v[i]];
          }
          return flag;
      }
      int countUnique(vector<vector<int>>& v)
      {
         int res = 0;
         for(int i=0;i<v.size();i++)
         {
             if(insert(v[i])) res++;
         }
         return res;
      }
};
int main(){
    vector<vector<int>> v{{1,1,0},{1,1,0},{1,1,1},{1,1,1}};
    Trie t;
    cout<<t.countUnique(v)<<'\n';
    return 0;
}