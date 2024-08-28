#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
Node* Reverse(Node* head)
{
      if(head==NULL || head->next==nullptr) return head;
      Node* curr = head,*prev=NULL;
      while(curr != nullptr)
      {
            prev = curr->prev;
            curr->prev=curr->next;
            curr->next=prev;

            curr = curr->prev;
      }
      return prev->prev;
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


     first =Reverse(first);
     Display(first);
     return 0;
}