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
Node* InsertAtBegin(Node* head,int data)
{ 
      Node* temp =  new Node(nullptr,data,head);
      if(head==NULL)
      {
           return temp;
      }
      head->prev=temp;
      return temp;
}
int main()
{
     Node* first,*second,*third;

     first = nullptr;
    /*second = new Node(20);
     third = new Node(30); 
     first->next=second;
     second->prev=first;
     second->next=third;
     third->prev=second;*/

     //first = InsertAtBegin(first,5);
     first = InsertAtBegin(first,1);

     Display(first);
     return 0;
}