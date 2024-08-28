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
int MiddleOfLL(Node* head)
{
      if(head==nullptr) return -1;
      Node* slow,*fast;
      slow=fast=head;
      while(fast!=nullptr && fast->next!=nullptr)
      {
            fast=fast->next->next;
            slow=slow->next;
      }
      return slow->data;
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
      LinkedListTraversal(head);
      cout<<MiddleOfLL(head)<<'\n';
      return 0;
}