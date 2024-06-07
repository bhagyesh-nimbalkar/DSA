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
      head->next->next = new Node(25);
      head->next->next->next = new Node(35);
      head->next->next->next->next = new Node(45);
      LinkedListTraversal(head);
      head = Reverse(head);
      LinkedListTraversal(head);
      return 0;
}