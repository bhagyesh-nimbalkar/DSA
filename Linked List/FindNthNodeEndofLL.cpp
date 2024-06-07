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
Node* FromEnd(Node* head,int n)
{
      if(head==nullptr) return nullptr;
      Node* slow,*fast;
      slow=fast=head;
      int cnt=1;
      while(fast!=nullptr && fast->next!=nullptr)
      {
            fast=fast->next->next;
            cnt+=2;
      }
      if(fast!=nullptr) cnt+=1;
      int toFind = cnt-n;
      if(toFind<1) return nullptr;
      toFind--;
      int i=0;
      while(i<toFind/2)
      {
           slow=slow->next->next;
           i++;
      }
      if(toFind&1) return slow->next;
      return slow;
}
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

int main()
{
      Node* head = new Node(10);
      head->next = new Node(20);
     // head->next->next = new Node(25);
      //head->next->next->next = new Node(35);
      LinkedListTraversal(head);
      Node* res = FromEnd(head,2);
      if(res==nullptr) cout<<"Invalid Argument\n";
      else cout<<res->data<<'\n';
      return 0;
}