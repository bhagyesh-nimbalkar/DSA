#include <bits/stdc++.h>
using namespace std;

struct Node{
     int data;
     Node* prev,*next;

     Node(int x)
     {
          data=x;
          prev=next=nullptr;
     }
     Node(Node* prev,int x,Node* next)
     {
           data =x;
           this->prev=prev;
           this->next = next;
     }
};
void Display(Node* head)
{
      while(head!=NULL)
      {
           cout<<head->data<<' ';    
           head = head->next;  
      }
      cout<<'\n';
}
Node* InsertAtEnd(Node* head,int data)
{
      Node* curr = head;
      Node* temp = new Node(data);
      if(head==NULL)  return temp;
      while(curr->next!=nullptr)
      {
             curr=curr->next;
      }
      curr->next=temp;
      temp->prev=curr;
      return head;
}
int main()
{
     Node* first,*second,*third;

     first = new Node(10);
     /*second = new Node(20);
     third = new Node(30); 
     first->next=second;
     second->prev=first;
     second->next=third;
     third->prev=second;*/


     first = InsertAtEnd(first,40);
     first = InsertAtEnd(first,50);
     Display(first);
     return 0;
}