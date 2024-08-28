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

void Traversal(Node* head)
{
     if(head==nullptr) return;
     cout<<head->data<<' ';
     Node* temp = head;
     temp = temp->next;
     while(temp!=head)
     {
          cout<<temp->data<<' ';
          temp=temp->next;
     }
     cout<<'\n';
     return;
}
Node* InsertAtBegin(Node* head,int x)
{
      Node* temp = new Node(x);
      if(head==nullptr)
      {
          temp->next=temp;
          return temp;
      }
      if(head==head->next)
      {
           temp->next=head;
           head->next=temp;
           return temp;
      }
      Node* curr = head;
      do{
          curr=curr->next;
      }while(curr->next!=head);
      temp->next=head;
      curr->next=temp;
      return temp;
}
int main()
{
     Node* first,*second,*third,*fourth;

     first = new Node(10);
     //second = new Node(20);
     /*third = new Node(30);
     fourth = new Node(40);*/

     first->next=first;
     //second->next=first;
     /*third->next=fourth;
     fourth->next=first;
    // first->next=first;*/

     first=InsertAtBegin(first,5);
     Traversal(first);
     return 0;
}