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
Node* DeleteHead(Node* head)
{
      if(head==nullptr) return nullptr;
      if(head->next==nullptr)
      { 
        delete head;
        return nullptr;
      }
      Node* temp = head;
      head=temp->next;
      head->prev=nullptr;
      delete temp;
      return head;
}
int main()
{
     Node* first,*second,*third,*fourth;

     //first = new Node(10);
     second = new Node(20);
     third = new Node(30);
     fourth = new Node(40);

     //first->next=second;
     //second->prev=first;
     second->next=third;
     third->prev=second;
     third->next=fourth;
     fourth->prev=third;

     first = DeleteHead(second);
     Traversal(first);
     return 0;
}