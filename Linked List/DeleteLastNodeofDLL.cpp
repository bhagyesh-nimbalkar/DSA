#include <bits/stdc++.h>
using namespace std;
struct Node{
     int data;
     Node* prev,*next;
     Node(int x)
     { 
          data=x;
          prev=nullptr;
          next=nullptr;
     }
};
void Traversal(Node* head)
{
     while(head!=nullptr)
     {
          cout<<head->data<<' ';
          head=head->next;
     }
     cout<<'\n';
}
Node* DeleteLast(Node* head)
{
      if(head==nullptr) return nullptr;
      Node* curr = head;
      while(curr->next!=nullptr)
      {
           curr=curr->next;
      }
      if(curr==head)
      {
         delete head;
         return nullptr;
      }
      curr->prev->next=nullptr;
      delete curr;
      return head;
}
int main()
{
     Node* first,*second,*third,*fourth;

     first = new Node(10);
     second = new Node(20);
     third = new Node(30);
     fourth = new Node(40);

     first->next=second;
     second->prev=first;
     second->next=third;
     third->prev=second;
     third->next=fourth;
     fourth->prev=third;

     first = DeleteLast(first);
     Traversal(first);
     return 0;
}