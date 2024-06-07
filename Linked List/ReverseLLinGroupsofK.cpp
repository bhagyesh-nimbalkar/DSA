#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x)
    {
          data=x;
          next=NULL;
    }
};

void LinkedListTraversal(Node* head)
{
     while(head!=nullptr)
     {
          cout<<head->data<<' ';
          head=head->next;
     }
     cout<<'\n';
     return;
}
Node* Reverse(Node* head)
{
      if(head==nullptr) return nullptr;
      if(head->next==nullptr) return head;

      Node* nxt=head->next,*curr=head,*prev=head;
      while(nxt!=nullptr)
      {
           if(curr==prev)
           {
                curr->next=nullptr;
           }
           else {
               curr->next=prev;
           }
           prev=curr;
           curr=nxt;
           nxt=nxt->next;
      }
      curr->next=prev;
      return curr;
}
Node* ReverseGroups(Node* head,int k)
{
     Node* start=head,*curr= head,*Finalhead=nullptr,*prev=nullptr;
     int cnt=1;
     while(curr!=nullptr)
     {
          if(cnt==k)
          {
               Node* store = curr->next;
               curr->next=nullptr;
               Node* temp = Reverse(start);
               if(prev!=nullptr)
               {
                   prev->next=temp;
               }
               prev = start;
               start=store;
               if(Finalhead==nullptr) Finalhead=temp;
               cnt=1;
               curr=store;
               continue;
          }
        curr=curr->next;
        cnt++;
     }
        Node* temp = Reverse(start);
        if(prev!=nullptr)
        {
          prev->next=temp;
        }
        if(Finalhead==nullptr) Finalhead=temp;
        return Finalhead;
}
int main()
{
      Node* head = new Node(10);
      head->next = new Node(20);
      head->next->next = new Node(30);
      head->next->next->next = new Node(40);
      head->next->next->next->next = new Node(50);
      head->next->next->next->next->next = new Node(60);
      head->next->next->next->next->next->next = new Node(70);

      LinkedListTraversal(head);
      head = ReverseGroups(head,2);
      LinkedListTraversal(head);
      return 0;
}