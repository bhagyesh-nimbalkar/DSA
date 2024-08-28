#include <bits/stdc++.h>
using namespace std;
struct Node{
      int data;
      Node* prev,*next;
      Node(int x)
      {
         data =x;
         prev=next=nullptr;
      }
};
class Solution{
      private:
         int cnt=0,Mcap=0;
         Node* MRU=nullptr,*LRU=nullptr;
         unordered_map<int,Node*> mp;
         void Display(){
            Node* curr = LRU;
            while(curr!=nullptr)
            {
                cout<<curr->data<<' ';
                curr=curr->next;
            }
            cout<<'\n';
         }
      public:
       Solution(int c){
            Mcap=c;
       }
       void PageRef(int x)
       {
             bool res = false;
             Node* ref  = nullptr;
             if(mp.find(x) == mp.end()) res=false;
             else {
                res=true;
                ref=mp[x];
             }
             Node* temp = new Node(x);
             if(!(res) && (cnt<Mcap))
             {
                   if(MRU==nullptr)
                   {
                      MRU = temp;
                      LRU = temp;
                      mp[x]=temp;
                      cnt++;
                   }
                   else {
                      temp->prev=MRU;
                      MRU->next=temp;
                      MRU = temp;
                      MRU->next=nullptr;
                      mp[x]=temp;
                      cnt++;
                   }
             }
             else if(!(res) && (cnt==Mcap))
             {
                     Node* store = LRU;
                     LRU = LRU->next;
                     mp[x]=temp;
                     mp.erase(store->data);
                     delete store;
                     temp->prev=MRU;
                     MRU->next=temp;
                     MRU = temp;
                     MRU->next=nullptr;
             }
             else
             {
                  if(ref==LRU)
                  { 
                       Node* store = LRU;
                       LRU = LRU->next;
                       store->prev=MRU;
                       MRU->next=store;
                       MRU = store;
                       MRU->next=nullptr;
                  }
                  else 
                  {
                       ref->prev->next=ref->next;
                       ref->next->prev=ref->prev;
                       ref->prev=MRU;
                       MRU->next=ref;
                       MRU=ref;
                       MRU->next=nullptr;
                  }
             }
             Display();
       }

};

int main()
{
    Solution s(2);
    vector<int> page{1,2,3,4};
    for(int i=0;i<page.size();i++)
    {
          s.PageRef(page[i]);
    }
    return 0;
}