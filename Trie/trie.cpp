#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isEnd;
    TrieNode* child[26];

    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++) child[i] = NULL;
    }
};
class Trie{
  private:
    TrieNode* root = new TrieNode();
  public:
    bool isEmpty(TrieNode* root)
    {
         for(int i=0;i<26;i++)
         {
             if(root->child[i]) return false;
         }
         return true;
    }
    TrieNode* delkey(TrieNode* root,string& s,int i)
    {
         if(!root) return NULL;
         if(i==s.size())
         {
             root->isEnd=false;
             if(isEmpty(root)){
                delete root;
                return NULL;
             }
             return root;
         }
         root->child[s[i]-'a'] = delkey(root->child[s[i]-'a'],s,i+1);
         if(isEmpty(root) && root->isEnd==false){
            delete root;
            return NULL;
         }
         return root;
    }
    void Delete(string s)
    {
        delkey(root,s,0);
    }
    void insert(string s)
    {
        TrieNode* curr = root;
        for(int i=0;i<s.size();i++)
        {
            if(!curr->child[s[i]-'a'])  curr->child[s[i]-'a']= new TrieNode();
            curr=curr->child[s[i]-'a'];
        }
        curr->isEnd=true;
    }
    bool search(string s)
    {
        TrieNode* curr = root;
        for(int i=0;i<s.size();i++)
        {
             if(!curr->child[s[i]-'a']) return false;
             curr=curr->child[s[i]-'a'];
        }
        return curr->isEnd;
    }
};
int main(){
    Trie t;
    t.insert("cat");
    t.insert("geek");
    t.insert("geeks");
    t.Delete("geeks");
    cout<<t.search("geek")<<'\n';
    return 0;
}