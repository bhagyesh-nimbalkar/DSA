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
Node* Recr(Node* head,Node* prev)
{
      if(head==nullptr) return prev;

      Node* nxt = head->next;
      head->next=prev;
      return Recr(nxt,head);
}
Node* RecrReverse(Node* head)
{
   return Recr(head,nullptr);
}

int main(){
      Node* head = new Node(10);
      head->next = new Node(20);
      head->next->next = new Node(30);
      head->next->next->next = new Node(40);

      Traversal(head);
      head = RecrReverse(head);
      Traversal(head);
      return 0;
}