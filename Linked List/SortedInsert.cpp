#include <bits/stdc++.h>
using namespace std;

struct Node{
      int data;
      Node* next;
      Node(int x)
      {
          data=x;
          next=nullptr;
      }
};

Node* SortedInsert(Node* head,int x)
{
      Node* temp = new Node(x);
      if(head==nullptr) 
      {
          return temp;
      }
      Node* curr = head;
      while(curr->next!=nullptr && curr->next->data<x)
      {
         curr=curr->next;
      }
      if(curr==head)
      {
          if(curr->data>=x)
          {
              temp->next=curr;
              return temp;
          }
      }
      temp->next=curr->next;
      curr->next=temp;
      return head;
}

void Traversal(Node* head)
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
     Node* first,*second,*third,*fourth;
     first = new Node(10);
     second = new Node(20);
    /* third = new Node(30);
     fourth = new Node(40);*/

     first->next=second;
    /* second->next =third;
     third->next=fourth;*/


     Traversal(first);
     first = SortedInsert(nullptr,30);
     Traversal(first);
     return 0;
}